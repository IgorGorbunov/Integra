#pragma once

#include "IntegrationSettings.h"
#include "IntegrationResult.h"
#include "ODBCclass.h"
#include "Book.h"
#include "DbBook.h"
#include "SemanticBook.h"
#include "Position.h"
#include "DbPosition.h"
#include "DiffererncePosition.h"
#include "Results2.h"
#include "Editting.h"
#include "Notice.h"
#include "RoughInterg.h"


namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Класс для р
	/// </summary>
	public ref class Integration
	{
	public:
		List<Position^>^ SourceNew;
		List<Position^>^ TargetNew;
		List<DifferencePosition^>^ Differences;

		List<List<Object^>^>^ SourceTabNew;
		List<List<Object^>^>^ TargetTabNew;

		int NinSource;
		int NinTarget;
		int Nequal;
		long Nmatches;

	private:
		Results2^ _resultForm;

		IntegrationSettings^ _settings;
		OdbcClass^ _odbc;
		List<AttributePair^>^ _attrPairs;
		List<Attribute^>^ _sourceAttrs;
		List<Attribute^>^ _targetAttrs;
		

		Book^ _sourceBook;
		Book^ _targetBook;
		List<Position^>^ _sourcePositions;
		List<Position^>^ _targetPositions;
		static List<Position^>^ _sourceStaicPositions;
		static List<Position^>^ _targetStaicPositions;
		List<Position^>^ _targetNewPositions;
		List<Position^>^ _sourceNewPositions;

		BackgroundWorker^ _backgroundWorker1;
		BackgroundWorker^ _backgroundWorker2;
		BackgroundWorker^ _bWorker;
		

		bool _firstWorkIsSemantic, _secondWorkIsSemantic;
		bool _isBusy;
		int maxColSource;
		int maxColTarget;

		List<IntegrationGroupPair^>^ _integGroupPairs;

		IntegrationResult^ _intgrResults;

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

		Dictionary<int, int>^ iPairs;


	public:
		Void StartExactIntegration(Form^% form, Label^% lblCount, bool isAuto)
		{
			int iType;
			if (isAuto)
			{
				iType = 0;
			}
			else
			{
				iType = 1;
			}

			_intgrResults = gcnew IntegrationResult(_odbc, _settings, iType);
			_intgrResults->WriteDbStart();

			_attrPairs = _settings->AttributePairs;
			SetAttrLists();

			_bWorker = nullptr;
			InitializeBackgoundWorkers();
			List<Position^>^ _sourcePositions;
			List<Position^>^ _targetPositions;

			bool secondIsSemantic = false;
			if (_settings->SourceBook->IsSemantic && !_settings->TargetBook->IsSemantic)
			{
				_bWorker = _backgroundWorker1;
				_targetBook = GetBook(_settings->TargetBook, false);
				_targetPositions = _targetBook->GetAllPositionsTable(_targetAttrs, _settings->TargetBook->DbFilters, _settings->TargetBook->DbLinks);
			}
			if (!_settings->SourceBook->IsSemantic && _settings->TargetBook->IsSemantic)
			{
				secondIsSemantic = true;
				_sourceBook = GetBook(_settings->SourceBook, true);
				_sourcePositions = _sourceBook->GetAllPositionsTable(_sourceAttrs, _settings->SourceBook->DbFilters, _settings->SourceBook->DbLinks);
				_bWorker = _backgroundWorker2;
			}
			
			if	(_bWorker == nullptr)
			{
				_sourceBook = GetBook(_settings->SourceBook, true);
				_targetBook = GetBook(_settings->TargetBook, false);
				_sourcePositions = _sourceBook->GetAllPositionsTable(_sourceAttrs, _settings->SourceBook->DbFilters, _settings->SourceBook->DbLinks);
				_targetPositions = _targetBook->GetAllPositionsTable(_targetAttrs, _settings->TargetBook->DbFilters, _settings->TargetBook->DbLinks);
			}
			else
			{
				_isBusy = true;
				_bWorker->RunWorkerAsync();
			}
			
			if (lblCount != nullptr)
				lblCount->Text = "0";
			Application::DoEvents();

			while (_bWorker != nullptr && _isBusy)
			{
				System::Threading::Thread::Sleep(1000);
			}

			Differences = gcnew List<DifferencePosition^>();
			SourceNew = gcnew List<Position ^>();
			TargetNew = gcnew List<Position ^>();

			if(_sourcePositions == nullptr)
			{
				_sourcePositions = _sourceStaicPositions;
			}
			NinSource = _sourcePositions->Count;
			if(_targetPositions == nullptr)
			{
				_targetPositions = _targetStaicPositions;
			}
			NinTarget = _targetPositions->Count;

			Nequal = 0;
			Nmatches = 0;
			if	(!secondIsSemantic)
			{
				for (int i = 0; i < _sourcePositions->Count; i++)
				{
					bool contains = false;
					Position^ sPos = _sourcePositions[i];
					sPos->SetEquivAttr(_settings->SourceEquivAttr);
					int jDel;
					for (int j = 0; j < _targetPositions->Count; j++)
					{
						Position^ tPos = _targetPositions[j];
						tPos->SetEquivAttr(_settings->TargetEquivAttr);
						Nmatches++;
						if (sPos->EqualValue == tPos->EqualValue)
						{
							contains = true;
							jDel = j;
							DifferencePosition^ diffPos;
							if (AttrsIsFullyEqual(sPos, tPos, diffPos))
							{
								Nequal++;
								break;
							}
							else
							{
								Differences->Add(diffPos);
								break;
							}
						}
					}
					if (contains)
					{
						_targetPositions->RemoveAt(jDel);
					}
					else
					{
						SourceNew->Add(sPos);
					}
					lblCount->Text = i + "";
					form->Update();
					form->Refresh();
				}
				TargetNew = _targetPositions;
			}
			else
			{
				for (int i = 0; i < _targetPositions->Count; i++)
				{
					bool contains = false;
					Position^ tPos = _targetPositions[i];
					tPos->SetEquivAttr(_settings->TargetEquivAttr);
					int jDel;
					for (int j = 0; j < _sourcePositions->Count; j++)
					{
						Position^ sPos = _sourcePositions[j];
						sPos->SetEquivAttr(_settings->SourceEquivAttr);
						Nmatches++;
						if (sPos->EqualValue == tPos->EqualValue)
						{
							contains = true;
							jDel = j;
							DifferencePosition^ diffPos;
							if (AttrsIsFullyEqual(sPos, tPos, diffPos))
							{
								Nequal++;
								break;
							}
							else
							{
								Differences->Add(diffPos);
								break;
							}
						}
					}
					if (contains)
					{
						_sourcePositions->RemoveAt(jDel);
					}
					else
					{
						TargetNew->Add(tPos);
					}
					lblCount->Text = i + "";
					form->Update();
					form->Refresh();
				}
				SourceNew = _sourcePositions;
			}
			


//List<Attribute^>^ attrSourceTitles;
// 			String^ sourceAttrIdName = _settings->SourceBook->AttrIdFullcode;
// 			String^ sourceAttrTitleName = _settings->SourceBook->AttrTitleFullcode;
// 			int iSAttrId = GetAttrId(attrSourceTitles, sourceAttrIdName);
// 			int iSAttrTitle = GetAttrId(attrSourceTitles, sourceAttrTitleName);
// 
// 			
// 			List<Attribute^>^ attrTargetTitles;
// 			
// 			String^ targetAttrIdName = _settings->TargetBook->AttrIdFullcode;
// 			String^ targetAttrTitleName = _settings->TargetBook->AttrTitleFullcode;
// 			int iTAttrId = GetAttrId(attrTargetTitles, targetAttrIdName);
// 			int iTAttrTitle = GetAttrId(attrTargetTitles, targetAttrTitleName);
// 
// 			iPairs = SetDictiPairs(_settings->AttributePairFullCodes, attrSourceTitles, attrTargetTitles);
// 			pairs = SetDictiPairs(_settings->AttributePairFullCodes, attrSourceTitles, attrTargetTitles);
// 
// 			SourceNew = gcnew List<Position^>();
// 			TargetNew = gcnew List<Position^>();
// 			Differences = gcnew List<DifferencePosition ^>();
// 			for (int i = 0; i < sourcePoses->Count; i += attrSourceTitles->Count)
// 			{
// 				bool find = false;
// 				String^ sVal = sourcePoses[i + iSAttrId]->ToString();
// 				for (int j = 0; j < _targetPoses->Count; j += attrTargetTitles->Count)
// 				{
// 					String^ tVal = _targetPoses[j + iTAttrId]->ToString();
// 					if (sVal == tVal)
// 					{
// 						List<Object^>^ sListingPos = GetPos(sourcePoses, attrSourceTitles->Count, i);
// 						List<Object^>^ tListingPos = GetPos(_targetPoses, attrTargetTitles->Count, j);
// 
// 						DifferencePosition^ diffPos = SetDiffPos(sListingPos, tListingPos,
// 											 attrSourceTitles, attrTargetTitles, iPairs, sVal);
// 						if (diffPos != nullptr)
// 						{
// 							Differences->Add(diffPos);
// 						}
// 						find = true;
// 						Remove(_targetPoses, attrTargetTitles->Count, j);
// 						break;
// 					}
// 				}
// 				if (!find)
// 				{
// 					List<Object^>^ sListingPos = GetPos(sourcePoses, attrSourceTitles->Count, i);
// 					Position^ p = gcnew DbPosition(sListingPos, attrSourceTitles, iSAttrId, iSAttrTitle);
// 					SourceNew->Add(p);
// 				}
// 				lblCount->Text = ++ii + "";
// 				Application::DoEvents();
// 			}
// 
// 			for (int i = 0; i < _targetPoses->Count; i += attrTargetTitles->Count)
// 			{
// 				List<Object^>^ sListingPos = GetPos(_targetPoses, attrTargetTitles->Count, i);
// 				Position^ p = gcnew DbPosition(sListingPos, attrSourceTitles, iSAttrId, iSAttrTitle);
// 				TargetNew->Add(p);
// 			}
		}

		void StartAutoExactIntegration()
		{
			StartExactIntegration(gcnew Form(), gcnew Label(), true);
		}

		void StartExeIntegration()
		{
			_intgrResults = gcnew IntegrationResult(_odbc, _settings, 3);
			_intgrResults->WriteDbStart();

			_attrPairs = _settings->AttributePairs;
			SetAttrLists();

			_bWorker = nullptr;
			InitializeBackgoundWorkers();
			List<Position^>^ _sourcePositions;

			bool secondIsSemantic = false;
			if (!_settings->SourceBook->IsSemantic && _settings->TargetBook->IsSemantic)
			{
				secondIsSemantic = true;
				_sourceBook = GetBook(_settings->SourceBook, true);
				_sourcePositions = _sourceBook->GetAllPositionsTable(_sourceAttrs, _settings->SourceBook->DbFilters, _settings->SourceBook->DbLinks);
				_bWorker = _backgroundWorker2;
			}

			if	(_bWorker == nullptr)
			{
				_sourceBook = GetBook(_settings->SourceBook, true);
				_sourcePositions = _sourceBook->GetAllPositionsTable(_sourceAttrs, _settings->SourceBook->DbFilters, _settings->SourceBook->DbLinks);
			}
			else
			{
				_isBusy = true;
				_bWorker->RunWorkerAsync();
			}


			while (_bWorker != nullptr && _isBusy)
			{
				System::Threading::Thread::Sleep(1000);
			}

			if(_sourcePositions == nullptr)
			{
				_sourcePositions = _sourceStaicPositions;
			}
			NinSource = _sourcePositions->Count;

			Nequal = 0;
			Nmatches = 0;

			String^ exePath = _settings->TargetBook->ExePath;
			
			for each (Position^ pos in _sourcePositions)
			{
				String^ exeAttrs = "";
				for each (KeyValuePair<Attribute^, String^>^ pair in pos->AttributesAndValues)
				{
					Attribute^ attr = pair->Key;
					exeAttrs += String::Format("{{ {0} ({1}) - {2} }}, ", attr->Name, attr->Code, pair->Value);
				}
				exeAttrs = exeAttrs->Substring(0, exeAttrs->Length - 2);
				Process::Start(exePath, exeAttrs);
			}
		}

		void StartIntegByOneGroup(IntegrationGroupPair^ integGroup)
		{
			int groupId;
			String^ sGrId;
			String^ tGrId;
			bool isGroup;
			if (integGroup == nullptr)
			{
				groupId = -1;
				sGrId = String::Empty;
				tGrId = String::Empty;
				isGroup = false;
			}
			else
			{
				groupId = integGroup->Id;
				sGrId = integGroup->SourceGroupId;
				tGrId = integGroup->TargetGroupId;
				isGroup = true;
			}

			_attrPairs = _settings->GetAttributePairs(groupId);

			_bWorker = nullptr;
			InitializeBackgoundWorkers();

			List<Position^>^ _sourcePositions;
			List<Position^>^ _targetPositions;

			bool secondIsSemantic = false;
			if (_settings->SourceBook->IsSemantic && !_settings->TargetBook->IsSemantic)
			{
				_bWorker = _backgroundWorker1;
				_targetBook = GetBook(_settings->TargetBook, false);
				_targetPositions = _targetBook->GetGroupPositionsTable(_settings->TargetBook->AttrPosGroupId, tGrId, _settings->TargetBook->GroupFullTable,
					_targetAttrs, _settings->TargetBook->DbFilters, _settings->TargetBook->DbLinks);
			}
			if (!_settings->SourceBook->IsSemantic && _settings->TargetBook->IsSemantic)
			{
				secondIsSemantic = true;
				_sourceBook = GetBook(_settings->SourceBook, true);
				_sourcePositions = _sourceBook->GetGroupPositionsTable(_settings->SourceBook->AttrPosGroupId, sGrId, _settings->SourceBook->GroupFullTable,
					_sourceAttrs, _settings->SourceBook->DbFilters, _settings->SourceBook->DbLinks);
				_bWorker = _backgroundWorker2;
			}

			if	(_bWorker == nullptr)
			{
				_sourceBook = GetBook(_settings->SourceBook, true);
				_targetBook = GetBook(_settings->TargetBook, false);
				_targetPositions = _targetBook->GetGroupPositionsTable(_settings->TargetBook->AttrPosGroupId, tGrId, _settings->TargetBook->GroupFullTable,
					_targetAttrs, _settings->TargetBook->DbFilters, _settings->TargetBook->DbLinks);
				_sourcePositions = _sourceBook->GetGroupPositionsTable(_settings->SourceBook->AttrPosGroupId, sGrId, _settings->SourceBook->GroupFullTable,
					_sourceAttrs, _settings->SourceBook->DbFilters, _settings->SourceBook->DbLinks);
			}
			else
			{
				_isBusy = true;
				_bWorker->RunWorkerAsync();
			}

			Application::DoEvents();

			while (_bWorker != nullptr && _isBusy)
			{
				System::Threading::Thread::Sleep(1000);
			}


			if(_sourcePositions == nullptr)
			{
				_sourcePositions = _sourceStaicPositions;
			}
			NinSource = _sourcePositions->Count;
			if(_targetPositions == nullptr)
			{
				_targetPositions = _targetStaicPositions;
			}
			NinTarget = _targetPositions->Count;

			Nequal = 0;
			Nmatches = 0;

			for (int i = 0; i < _sourcePositions->Count; i++)
			{
				bool contains = false;
				Position^ sPos = _sourcePositions[i];

				List<Position^>^ similarPoses = gcnew List<Position ^>();
				for (int j = 0; j < _targetPositions->Count; j++)
				{
					Position^ tPos = _targetPositions[j];
					Nmatches++;
					if (HaveSomeSimilar(sPos, tPos))
					{
						similarPoses->Add(tPos);
					}
				}
				if (similarPoses->Count > 0)
				{
					RoughInterg^ form = gcnew RoughInterg(_odbc, integGroup, _settings, sPos, similarPoses, isGroup, _targetPositions);
					form->ShowDialog();
					sPos = form->Spos;

					if (form->NotFound)
					{
						SourceNew->Add(sPos);
					}
					else if (form->IsSelect)
					{
						DifferencePosition^ diffPos;
						if (AttrsIsFullyEqual(sPos, form->SelectPosition, diffPos))
						{
							
						}
						else
						{
							Differences->Add(diffPos);
						}
					}

				}
			}
		}


		bool HaveSomeSimilar(Position^ sPos, Position^ tPos)
		{
			String^ sRoughAttrValue = sPos->GetValue(_settings->SourceBook->RoughAttr);
			String^ tRoughAttrValue = tPos->GetValue(_settings->TargetBook->RoughAttr);
			array<String^, 1>^ arr1 = sRoughAttrValue->Split(_settings->SourceBook->RoughSymbols, System::StringSplitOptions::RemoveEmptyEntries);
			array<String^, 1>^ arr2 = tRoughAttrValue->Split(_settings->TargetBook->RoughSymbols, System::StringSplitOptions::RemoveEmptyEntries);

			for each (String^ arr1Bit in arr1)
			{
				for each (String^ arr2Bit in arr2)
				{
					if (arr1Bit->ToUpper()->Trim() == arr2Bit->ToUpper()->Trim())
					{
						return true;
					}
				}
			}
			return false;
		}

		void StartRoughIntegration()
		{
			_intgrResults = gcnew IntegrationResult(_odbc, _settings, 2);
			_intgrResults->WriteDbStart();

			SetAttrLists();

			_integGroupPairs = IntegrationGroupPair::GetGroups(_odbc, _settings->Id);

			Differences = gcnew List<DifferencePosition^>();
			SourceNew = gcnew List<Position ^>();
			TargetNew = gcnew List<Position ^>();


			if (_integGroupPairs == nullptr || _integGroupPairs->Count <= 0)
			{
				StartIntegByOneGroup(nullptr);
			}
			else
			{
				for each (IntegrationGroupPair^ integGroup in _integGroupPairs)
				{
					StartIntegByOneGroup(integGroup);
				}
			}
		}

		void StopIntegration()
		{
			_intgrResults->StopIntegration();
		}

		void AddPosToSource2(Position^ p)
		{
			/*Dictionary<Attribute^, String^>^ newAttrsAndVals = gcnew Dictionary<Attribute ^, String ^>();
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in _attrPairs)
			{
			if (p->AttributesAndValues->ContainsKey(pair->Value))
			{
			newAttrsAndVals->Add(pair->Key, p->AttributesAndValues[pair->Value]);
			}
			}
			_sourceBook->AddPosition(newAttrsAndVals, p->UnicId, _intgrResults, 0);*/
		}

		void AddPosToSource(Position^ p)
		{
			Dictionary<Attribute^, String^>^ newAttrsAndVals = gcnew Dictionary<Attribute ^, String ^>();
			for each (AttributePair^ attrPair in _attrPairs)
			{
				if (attrPair->SimpleSourceAttribute != nullptr)
				{
					newAttrsAndVals->Add(attrPair->SimpleSourceAttribute, attrPair->TargetValue);
				}
			}
			_sourceBook->AddPosition(newAttrsAndVals, p->EqualValue, p->Caption, _intgrResults, 0);
		}

		void AddPosToTarget(Position^ p)
		{
			Dictionary<Attribute^, String^>^ newAttrsAndVals = gcnew Dictionary<Attribute ^, String ^>();
			for each (AttributePair^ attrPair in _attrPairs)
			{
				attrPair->SetSourceValues(p->AttributesAndValues, nullptr);


				if (attrPair->SimpleTargetAttribute != nullptr)
				{
					for each (KeyValuePair<Attribute^, String^>^ pair in p->AttributesAndValues)
					{
						Attribute^ attr = pair->Key;
						String^ str = pair->Value;
					}
					
					newAttrsAndVals->Add(attrPair->SimpleTargetAttribute, attrPair->SourceValue);
					
				}
			}
			_targetBook->AddPosition(newAttrsAndVals, p->EqualValue, p->Caption, _intgrResults, 1);
		}

		void AddPosToTarget2(Position^ p)
		{
			/*Dictionary<Attribute^, String^>^ newAttrsAndVals = gcnew Dictionary<Attribute ^, String ^>();
			for each (KeyValuePair<Attribute^, Attribute^>^ pair in _attrPairs)
			{
			if (p->AttributesAndValues->ContainsKey(pair->Key))
			{
			newAttrsAndVals->Add(pair->Value, p->AttributesAndValues[pair->Key]);
			}
			}
			_targetBook->AddPosition(newAttrsAndVals, p->UnicId, _intgrResults, 1);*/
		}

		void UpdatePosToTarget(Position^ currentPos, Dictionary<Attribute^, String^>^ newAttrVals)
		{
			_targetBook->UpdatePositionForEachAttr(currentPos, newAttrVals, _intgrResults, 1);
		}

		void UpdatePosToSource(Position^ currentPos, Dictionary<Attribute^, String^>^ newAttrVals)
		{
			_sourceBook->UpdatePositionForEachAttr(currentPos, newAttrVals, _intgrResults, 0);
		}

		void NoticeRemoveFromSource(Position^ currentPos)
		{
			Notice^ notice = gcnew Notice(_odbc, _intgrResults->Id, "На удаление", currentPos->UnicId, currentPos->Caption, _settings->SourceBook->Id);
			notice->InsertToDb();
		}

		void NoticeRemoveFromTarget(Position^ currentPos)
		{
			Notice^ notice = gcnew Notice(_odbc, _intgrResults->Id, "На удаление", currentPos->UnicId, currentPos->Caption, _settings->TargetBook->Id);
			notice->InsertToDb();
		}


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
				for each(KeyValuePair<Attribute^, String^>^ pair in sourcePos->AttributesAndValues)
				{
					c1 += pair->Key->Code + " - " + pair->Value + ", ";
				}

				String^ c2 = "";
				for each(KeyValuePair<Attribute^, String^>^ pair in targetPos->AttributesAndValues)
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

		void SetAttrLists()
		{
			_sourceAttrs = _settings->SourceBook->Attributes;
			_targetAttrs = _settings->TargetBook->Attributes;

		}

		int GetAttrId(List<Attribute^>^ list, String^ name)
		{
			for (int i = 0; i < list->Count; i++)
			{
				if (name == list[i]->FullCode)
				{
					return i;
				}
			}
			return -1;
		}

		void Remove(List<Object^>^% list, int nDels, int j)
		{
			for (int i = 0; i < nDels; i++)
			{
				list->RemoveAt(j);
			}
		}

		List<Object^>^ GetPos(List<Object^>^ list, int nAdds, int j)
		{
			List<Object^>^ list1 = gcnew List<Object ^>();
			for (int i = j; i < nAdds + j; i++)
			{
				list1->Add(list[i]->ToString());
			}
			return list1;
		}

		/*DifferencePosition^ SetDiffPos(List<Object^>^ sPos, List<Object^>^ tPos, List<Attribute^>^ sTitles, List<Attribute^>^ tTitles, Dictionary<int, int>^ iPairs, String^ id)
		{
			DifferencePosition^ pos = gcnew DifferencePosition(id);
			bool different;
			for each (KeyValuePair<int, int>^ pair in iPairs)
			{
				String^ sVal = sPos[pair->Key]->ToString()->Trim();
				String^ tVal = tPos[pair->Value]->ToString()->Trim();
				if (sVal != tVal)
				{
					pos->AddDifferenceAttr(sTitles[pair->Key], sVal, tTitles[pair->Value], tVal);
					different = true;
				}
				else
				{
					pos->AddEqualAttr(sTitles[pair->Key], tTitles[pair->Value], sVal);
				}
			}
			if (different)
			{
				return pos;
			}
			return nullptr;
		}*/

		Dictionary<int, int>^ SetDictiPairs(List<String^>^ names, List<Attribute^>^ sourceAttrs, List<Attribute^>^ targetAttrs)
		{
			Dictionary<int, int>^ dict = gcnew Dictionary<int, int>();
			for (int i = 0; i < names->Count; i+=2)
			{
				int iS = GetAttrId(sourceAttrs, names[i]);
				int iT = GetAttrId(targetAttrs, names[i+1]);
				dict->Add(iS, iT);
			}
			return dict;
		}

		bool AttrsIsFullyEqual(Position^ sourcePos, Position^ targetPos, DifferencePosition^% diffPos)
		{
			bool equal = true;
			diffPos = gcnew DifferencePosition(sourcePos->UnicId, sourcePos,  targetPos);
			for (int i = 0; i < _attrPairs->Count; i++)
			{
				AttributePair^ newAttrPair = nullptr;
				newAttrPair = gcnew AttributePair(_attrPairs[i]);
				if (_attrPairs[i]->CheckEqual(sourcePos->AttributesAndValues, sourcePos->GroupingAttrs, 
												targetPos->AttributesAndValues, targetPos->GroupingAttrs))
				{
					diffPos->AddEqualAttr(newAttrPair);
				}
				else
				{
					equal = false;
					diffPos->AddDifferenceAttr(newAttrPair);
				}
			}
			return equal;
		}

		bool AttrsIsFullyEqual2(Position^ sourcePos, Position^ targetPos, DifferencePosition^% diffPos)
		{
			/*bool equal = true;
			diffPos = gcnew DifferencePosition(sourcePos->UnicId, sourcePos,  targetPos);
			for each (KeyValuePair<Attribute^, String^>^ pair in sourcePos->AttributesAndValues)
			{
				Attribute^ sAttr = pair->Key;
				String^ sValue = pair->Value;

				if (_settings->AttributePairs->ContainsKey(sAttr))
				{
					Attribute^ pAttr = _settings->AttributePairs[sAttr];
					String^ tValue = targetPos->AttributesAndValues[pAttr];

					Object^ sVal;
					Object^ tVal;
					if	(IsBothDouble(sValue, tValue))
					{
						sVal = Double::Parse(sValue);
						tVal = Double::Parse(tValue);
					}
					else
					{
						sVal = sValue->Trim();
						tVal = tValue->Trim();
					}

					if (sVal->ToString() != tVal->ToString())
					{
						equal = false;
						diffPos->AddDifferenceAttr(sAttr, sValue, pAttr, tValue);
					}
					else
					{
						diffPos->AddEqualAttr(sAttr, pAttr, tValue);
					}
				}
			}
			return equal;*/
			return false;
		}

		bool IsBothDouble(String^ sVal1, String^ sVal2)
		{
            sVal1 = sVal1->Replace('.', ',');
            sVal2 = sVal2->Replace('.', ',');
            Double d1;
			Double d2;
            bool b1 = Double::TryParse(sVal1, d1);
            bool b2 = Double::TryParse(sVal2, d2);
            if (b1 && b2)
            {
                return true;
            }
            else
            {
                return false;
            }
		}

		Book^ GetBook(BookSettings^ bookSettings, bool isSource)
		{
			if (bookSettings->IsSemantic)
			{
				return gcnew SemanticBook(bookSettings, _settings, _odbc, isSource);
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
			/*if (_resultForm == nullptr && Application::OpenForms["Results2"] == nullptr && _resultForm->IsBusy)
			{
				System::Threading::Thread::Sleep(1000);
			}*/

			/*_resultForm->LblSourceStatus->Text = "В процессе";
			_resultForm->LblSourceStatus->ForeColor = Color::Yellow;*/

			//_sourceBook = GetBook(_settings->SourceBook, true);
			_sourceBook = GetBook(_settings->SourceBook, true);
			BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
			_sourceStaicPositions = _sourceBook->GetAllPositions2(_bWorker, e);
			_isBusy = false;
		}

		void backgroundWorker1_RunWorkerCompleted( Object^ /*sender*/, RunWorkerCompletedEventArgs^ e )
		{
			/*if ( e->Error != nullptr )
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
			}*/
			_isBusy = false;

		}

		void backgroundWorker1_ProgressChanged( Object^ /*sender*/, ProgressChangedEventArgs^ e )
		{
			/*if (e->UserState == nullptr)
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
			}*/
		}

		void backgroundWorker2_DoWork( Object^ sender, DoWorkEventArgs^ e )
		{
			/*while (_resultForm == nullptr && Application::OpenForms["Results2"] == nullptr)
			{
				System::Threading::Thread::Sleep(1000);
			}
			_resultForm->LblTargetStatus->Text = "В процессе";
			_resultForm->LblTargetStatus->ForeColor = Color::Yellow;
			

			_targetBook = GetBook(_settings->TargetBook, false);*/
			_targetBook = GetBook(_settings->TargetBook, false);
			BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
			_targetStaicPositions = _targetBook->GetAllPositions2(worker, e);
			_isBusy = false;
		}

		void backgroundWorker2_RunWorkerCompleted( Object^ /*sender*/, RunWorkerCompletedEventArgs^ e )
		{
			/*if ( e->Error != nullptr )
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
			}*/
			_isBusy = false;
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