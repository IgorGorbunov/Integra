#pragma once

#include "IntegrationSettings.h"
#include "ODBCclass.h"
#include "Book.h"
#include "DbBook.h"
#include "SemanticBook.h"
#include "Position.h"
#include "DiffererncePosition.h"
#include "Results2.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс для р
	/// </summary>
	public ref class Integration
	{
	public:
		List<Position^>^ SourceNew;
		List<Position^>^ TargetNew;
		List<DifferencePosition^>^ Differences;

	private:
		Results2^ _resultForm;

		IntegrationSettings^ _settings;
		OdbcClass^ _odbc;
		

		Book^ _sourceBook;
		Book^ _targetBook;
		List<Position^>^ _sourcePositions;
		List<Position^>^ _targetPositions;
		List<Position^>^ _targetNewPositions;
		List<Position^>^ _sourceNewPositions;

		BackgroundWorker^ _backgroundWorker1;
		BackgroundWorker^ _backgroundWorker2;
		

		bool _firstWorkIsSemantic, _secondWorkIsSemantic;
		int maxColSource;
		int maxColTarget;

	public:
		Integration(IntegrationSettings^ settings, OdbcClass^ odbc) 
		{
			_odbc = odbc;
			_settings = settings;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Integration() 
		{

		}

	public:
		Void SetPositionsAndCompare()
		{

			
			if (_settings->SourceBook->IsSemantic && !_settings->TargetBook->IsSemantic)
			{
				_firstWorkIsSemantic = true;
				_secondWorkIsSemantic = false;
			}
			if (!_settings->SourceBook->IsSemantic && _settings->TargetBook->IsSemantic)
			{
				_firstWorkIsSemantic = true;
				_secondWorkIsSemantic = false;
			}

			_targetBook = GetBook(_settings->TargetBook, false);
			_resultForm = gcnew Results2(_targetBook);

			SourceNew = gcnew List<Position ^>();
			TargetNew = gcnew List<Position ^>();

			InitializeBackgoundWorkers();
			_resultForm->Worker = _backgroundWorker1;
			_backgroundWorker1->RunWorkerAsync();
			//_backgroundWorker2->RunWorkerAsync();

			_resultForm->ShowDialog();
		}

		void InitializeBackgoundWorkers()
		{
			_backgroundWorker1 = gcnew BackgroundWorker();
			_backgroundWorker1->WorkerReportsProgress = true;
			_backgroundWorker1->WorkerSupportsCancellation = true;
			_backgroundWorker1->DoWork += gcnew DoWorkEventHandler( this, &Integration::backgroundWorker1_DoWork );
			_backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler( this, &Integration::backgroundWorker1_RunWorkerCompleted );
			_backgroundWorker1->ProgressChanged += gcnew ProgressChangedEventHandler( this, &Integration::backgroundWorker1_ProgressChanged );

			_backgroundWorker2 = gcnew BackgroundWorker();
			_backgroundWorker2->WorkerReportsProgress = true;
			_backgroundWorker2->WorkerSupportsCancellation = true;
			_backgroundWorker2->DoWork += gcnew DoWorkEventHandler( this, &Integration::backgroundWorker2_DoWork );
			_backgroundWorker2->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler( this, &Integration::backgroundWorker2_RunWorkerCompleted );
			_backgroundWorker2->ProgressChanged += gcnew ProgressChangedEventHandler( this, &Integration::backgroundWorker2_ProgressChanged );
		}

		Void SetPositions()
		{
			_sourceBook = GetBook(_settings->SourceBook, true);
			_sourcePositions = _sourceBook->GetAllPositions();
			_targetBook = GetBook(_settings->TargetBook, false);
			_targetPositions = _targetBook->GetAllPositions();

		}

		Void CompareAll()
		{
			Differences = gcnew List<DifferencePosition^>();
			SourceNew = gcnew List<Position ^>();
			TargetNew = gcnew List<Position ^>();

			_targetNewPositions = _targetPositions;
			for each (Position^ sourcePos in _sourcePositions)
			{
				CompareSource(sourcePos);
			}
			TargetNew = _targetPositions;
		}

		void CompareSource(Position^ sourcePos)
		{
			bool contains = false;
			Position^ delPos;
			for each (Position^ targetPos in TargetNew)
			{
				delPos = targetPos;
				String^ c1 = "";
				for each(KeyValuePair<Attribute^, String^>^ pair in sourcePos->Attributes)
				{
					c1 += pair->Key->Code + " - " + pair->Value + ", ";
				}

				String^ c2 = "";
				for each(KeyValuePair<Attribute^, String^>^ pair in targetPos->Attributes)
				{
					c2 += pair->Key->Code + " - " + pair->Value + ", ";
				}

				if (sourcePos->UnicId == targetPos->UnicId)
				{
					contains = true;
					DifferencePosition^ diffPos;
					if (AttrsIsFullyEqual(sourcePos, targetPos, diffPos))
					{
						break;
					}
					else
					{
						Differences->Add(diffPos);
						_resultForm->SetNewDiff(diffPos);
						_resultForm->Differences->Add(diffPos);
						break;
					}
				}
			}
			if (contains)
			{
				TargetNew->Remove(delPos);
			}
			else
			{
				SourceNew->Add(sourcePos);
				_resultForm->SetNewSource(sourcePos);
			}
		}

	private:
		bool AttrsIsFullyEqual(Position^ sourcePos, Position^ targetPos, DifferencePosition^% diffPos)
		{
			bool equal = true;
			diffPos = gcnew DifferencePosition(sourcePos->UnicId);
			for each (KeyValuePair<Attribute^, String^>^ pair in sourcePos->Attributes)
			{
				Attribute^ sAttr = pair->Key;
				String^ sValue = pair->Value;
				Attribute^ pAttr = _settings->AttributePairs[sAttr];
				String^ tValue = targetPos->Attributes[pAttr];

				if (sValue->Trim() != tValue->Trim())
				{
					equal = false;
					diffPos->AddDifferenceAttr(sAttr, sValue, pAttr, tValue);
				}
				else
				{
					diffPos->AddEqualAttr(sAttr, pAttr, tValue);
				}
			}
			return equal;
		}


		Book^ GetBook(BookSettings^ bookSettings, bool isSource)
		{
			if (bookSettings->IsSemantic)
			{
				return gcnew SemanticBook(bookSettings, _settings, _odbc, isSource, _odbc);
			} 
			else
			{
				return gcnew DbBook(bookSettings, _settings, isSource, _odbc);
			}
			return nullptr;
		}

		void InitializeBackgoundWorker(BackgroundWorker^ backgroundWorker)
		{
			backgroundWorker = gcnew BackgroundWorker();
			backgroundWorker->WorkerReportsProgress = true;
			backgroundWorker->WorkerSupportsCancellation = true;
		}

		void backgroundWorker1_DoWork( Object^ sender, DoWorkEventArgs^ e )
		{
			if (_resultForm == nullptr && Application::OpenForms["Results2"] == nullptr && _resultForm->IsBusy)
			{
				System::Threading::Thread::Sleep(1000);
			}
			TargetNew = _resultForm->TargetPositions;
			Differences = gcnew List<DifferencePosition ^>();

			_resultForm->LblSourceStatus->Text = "В процессе";
			_resultForm->LblSourceStatus->ForeColor = Color::Yellow;
			BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

			_sourceBook = GetBook(_settings->SourceBook, true);
			_sourcePositions = _sourceBook->GetAllPositions2(worker, e);
		}

		void backgroundWorker1_RunWorkerCompleted( Object^ /*sender*/, RunWorkerCompletedEventArgs^ e )
		{
			if ( e->Error != nullptr )
			{
				MessageBox::Show( e->Error->Message );
			}
			else if ( e->Cancelled )
			{
				_resultForm->LblSourceStatus->Text = "Отменено";
				_resultForm->LblSourceStatus->ForeColor = Color::Red;
				_resultForm->bCancel->Enabled = false;
			}
			else
			{
				_resultForm->LblSourceStatus->Text = "Завершено";
				_resultForm->LblSourceStatus->ForeColor = Color::Green;
				_resultForm->bCancel->Enabled = false;

				for each(Position^ pos in TargetNew)
				{
					_resultForm->SetNewTarget(pos);
				}
			}
		}

		void backgroundWorker1_ProgressChanged( Object^ /*sender*/, ProgressChangedEventArgs^ e )
		{
			if (e->UserState == nullptr)
			{
				_resultForm->LblSourceCount->Text = e->ProgressPercentage + "";
			}
			else
			{
				_resultForm->LblSourceCount->Text = e->ProgressPercentage + "";
				Position^ pos = (Position^)e->UserState;
				while (_backgroundWorker2->IsBusy)
				{
					System::Threading::Thread::Sleep(1000);
				}
				CompareSource(pos);
			}
		}

		void backgroundWorker2_DoWork( Object^ sender, DoWorkEventArgs^ e )
		{
			while (_resultForm == nullptr && Application::OpenForms["Results2"] == nullptr)
			{
				System::Threading::Thread::Sleep(1000);
			}
			_resultForm->LblTargetStatus->Text = "В процессе";
			_resultForm->LblTargetStatus->ForeColor = Color::Yellow;
			BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);

			_targetBook = GetBook(_settings->TargetBook, false);
			_targetPositions = _targetBook->GetAllPositions2(worker, e);
			
			
		}

		void backgroundWorker2_RunWorkerCompleted( Object^ /*sender*/, RunWorkerCompletedEventArgs^ e )
		{
			if ( e->Error != nullptr )
			{
				MessageBox::Show( e->Error->Message );
			}
			else if ( e->Cancelled )
			{
				_resultForm->LblTargetStatus->Text = "Отменено";
				_resultForm->LblTargetStatus->ForeColor = Color::Red;
			}
			else
			{
				_resultForm->LblTargetStatus->Text = "Завершено";
				_resultForm->LblTargetStatus->ForeColor = Color::Green;
			}
		}

		void backgroundWorker2_ProgressChanged( Object^ /*sender*/, ProgressChangedEventArgs^ e )
		{
			if (e->UserState == nullptr)
			{
				_resultForm->LblTargetCount->Text = e->ProgressPercentage + "";
			}
			
		}
	};
}