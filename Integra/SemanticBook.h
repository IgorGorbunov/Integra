#pragma once

#include "Logger.h"
#include "Semantic.h"
#include "SemanticPosition.h"
#include "IntegrationSettings.h"
#include "Book.h"
#include "Position.h"
#include "Results2.h"


namespace Integra {

	using namespace System::Collections::Generic;
	//using namespace SemanticCore;

	/// <summary>
	/// Класс spravochnika Semantic
	/// </summary>
	public ref class SemanticBook : Book
	{

	private:
		Semantic^ _semantic;
		BookSettings^ BookSetting;
		IntegrationSettings^ _intSettings;

		Object^ _root;
		List<String^>^ _tables;
		String^ _title;
		List<Attribute^>^ _attributes;
		Attribute^ _equivAttr;

		int _i;

	public:
		SemanticBook(BookSettings^ bookSettings, IntegrationSettings^ intSettings, OdbcClass^ odbc, bool isSource) : Book(bookSettings, intSettings, odbc)
		{
			/*_bookSettings = bookSettings;
			_intSettings = intSettings;
			_commonOdbc = commonOdbc;
			_semantic = gcnew Semantic(_bookSettings->Login, _bookSettings->Password);
			_semantic->WriteToLog("-------------- Spravochnik ---------");
			if (isSource)
			{
				SetTitle(GetSourceTitle());
				_attributes = intSettings->SourceAttributes;
				_equivAttr = _intSettings->SourceEquivAttr;
			} 
			else
			{
				SetTitle(GetTargetTitle());
				_attributes = intSettings->TargetAttributes;
				_equivAttr = _intSettings->TargetEquivAttr;
			}
			_title = _title->Substring(1);
			_semantic->WriteToLog("title - " + _title);
			SetBookObject();
			_i = 0;*/
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SemanticBook() 
		{
			
		}

	public:
		virtual Dictionary<String^, String^>^ GetAllGroupNames() override
		{
			return nullptr;
		}

		virtual Object^ GetGroupAttrValue(Attribute^ attribute, String^ idGroup) override
		{
			return nullptr;
		}

		virtual List<Position^>^ GetAllPositions() override
		{
			return GetMaxLevelPositions();
		}
		virtual List<Position^>^ GetAllPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs ^ e) override
		{
			return GetMaxLevelPositions2(worker, e);
		}
		virtual List<Position^>^ GetAllPositions22(int% n) override
		{
			n = 0;
			return nullptr;
		}

		virtual List<Position^>^ GetAllPositionsTable(List<Attribute^>^ attrs) override
		{
			return nullptr;
		}

		virtual void AddPosition(Dictionary<Attribute^, String^>^ attrsAndNewVals) override
		{

		}

		virtual void UpdatePosition(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals) override
		{

		}

		virtual void UpdatePositionForEachAttr(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals, IntegrationResult^ result, int isTarget) override
		{

		}

	private:
		Void SetBookObject()
		{
			//_root = _semantic->Core->ObjectList()->GetRootObject(_title);
		}

		

		Void SetTitle(List<Object^>^ query)
		{
			_tables = gcnew List<String ^>();
			_title = "";
			for each(Object^ o in query)
			{
				_tables->Add(o->ToString());
				if (!String::IsNullOrEmpty(_title))
				{
					_title += ", ";
				}
				_title += o->ToString();
			}
		}

		List<Position^>^ GetChildPositions(List<Position^>^ positions)
		{
			List<Position^>^ list = gcnew List<Position ^>();
			for each (SemanticPosition^ pos in positions)
			{
				if (pos->IsGroup)
				{
					list->AddRange(GetChildPositions(pos->GetChildPositions()));
				}
				else
				{
					list->Add(pos);
				}
			}
			return list;
		}

		List<Position^>^ GetChildPositions2(List<Position^>^ positions, System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs ^ e)
		{
			List<Position^>^ list = gcnew List<Position ^>();
			for each (SemanticPosition^ pos in positions)
			{
				if (pos->IsGroup)
				{
					if ( worker->CancellationPending )
					{
						e->Cancel = true;
						break;
					}
					List<Position^>^ rangeList = GetChildPositions2(pos->GetChildPositions(), worker, e);
					list->AddRange(rangeList);
				}
				else
				{
					_i++;
					list->Add(pos);
					worker->ReportProgress(_i, pos);
					if ( worker->CancellationPending )
					{
						e->Cancel = true;
						break;
					}
				}
			}
			return list;
		}

		List<Position^>^ GetMaxLevelPositions()
		{
			SemanticPosition^ rootPos = gcnew SemanticPosition(_root, _attributes, _equivAttr);
			return GetChildPositions(rootPos->GetChildPositions());

		}

		List<Position^>^ GetMaxLevelPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs ^ e)
		{
			SemanticPosition^ rootPos = gcnew SemanticPosition(_root, _attributes, _equivAttr);
			return GetChildPositions2(rootPos->GetChildPositions(), worker, e);

		}


	};
}