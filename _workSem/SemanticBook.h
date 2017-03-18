#pragma once

#include "Logger.h"
#include "Semantic.h"
#include "SemanticPosition.h"
#include "IntegrationSettings.h"
#include "Book.h"
#include "Position.h"
#include "Results2.h"
#include "Editting.h"


namespace Integra {

	using namespace System::Collections::Generic;
	using namespace SemanticCore;

	/// <summary>
	/// Класс spravochnika Semantic
	/// </summary>
	public ref class SemanticBook : Book
	{

	private:
		Semantic^ _semantic;
		BookSettings^ _bookSettings;
		IntegrationSettings^ _intSettings;
		OdbcClass^ _commonOdbc;

		ISCObject^ _root;
		List<String^>^ _tables;
		String^ _title;
		List<Attribute^>^ _attributes;

		Attribute^ _equivAttr;
		

		int _i;

		Dictionary<Attribute^, String^>^ _attrNewVals;


	public:
		SemanticBook(BookSettings^ bookSettings, IntegrationSettings^ intSettings, OdbcClass^ commonOdbc, bool isSource) : Book(bookSettings, intSettings, commonOdbc)
		{
			_bookSettings = bookSettings;
			_intSettings = intSettings;
			_commonOdbc = commonOdbc;
			_semantic = gcnew Semantic(_bookSettings->Login, _bookSettings->Password);
			_semantic->WriteToLog("-------------- Spravochnik ---------");
			if (isSource)
			{
				SetTitle(GetSourceTitle());
				_attributes = intSettings->SimpleSourceAttributes;
				_equivAttr = _intSettings->SourceEquivAttr;
			} 
			else
			{
				SetTitle(GetTargetTitle());
				_attributes = intSettings->SimpleTargetAttributes;
				_equivAttr = _intSettings->TargetEquivAttr;
			}
			//_title = _title->Substring(1);
			_semantic->WriteToLog("title - " + _title);
			SetBookObject();
			_i = 0;
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SemanticBook() 
		{
			
		}

	public:
		

		

		virtual List<Position^>^ GetAllPositions() override
		{
			return GetMaxLevelPositions();
		}

		virtual List<Position^>^ GetAllPositionsTable(List<Attribute^>^ attrs, List<Object^>^ filters, List<Object^>^ links) override
		{
			return nullptr;
		}

		virtual List<Position^>^ GetGroupPositionsTable(Attribute^ groupAttr, String^ dbGroupId, String^ groupFullTable, List<Attribute^>^ attrs, List<Object^>^ filters, List<Object^>^ links) override
		{

			return nullptr;
		}

		virtual Dictionary<String^, String^>^ GetAllGroupNames() override
		{
			return nullptr;
		}

		virtual Object^ GetGroupAttrValue(Attribute^ attribute, String^ idGroup) override
		{
			return nullptr;
		}

		virtual Object^ GetPosAttrValue(Attribute^ attribute, String^ idPos) override
		{
			return nullptr;
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

		virtual void AddPosition(Dictionary<Attribute^, String^>^ attrsAndNewVals, Object^ idVal, Object^ titleVal, IntegrationResult^ result, int isTarget) override
		{
			CheckGroups(attrsAndNewVals);
		}

		virtual void UpdatePosition(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals) override
		{
			
		}

		virtual void UpdatePositionForEachAttr(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals, IntegrationResult^ result, int isTarget) override
		{
			SemanticPosition^ semPos = (SemanticPosition^)currentPos;
			for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
			{
				Attribute^ attr = pair->Key;
				String^ attrVal = pair->Value;

				semPos->UpdateAttr(attr, attrVal);
				Editting^ newEdit = gcnew Editting(_odbc, result, 1, isTarget, currentPos->UnicId, attr, currentPos->GetValue(attr), attrVal);
				newEdit->WriteEditingPos();
			}
		
		}

		
		virtual Object^ GetSemObject(String^ location) override
		{
			return _semantic->Core->ObjectList()->ObjectByLocation(location);
		}

		



	private:
		Void SetBookObject()
		{
			array<String^, 1>^ split = _title->Split('.');
			String^ lastClassCode = split[1];


			_root = _semantic->Core->ObjectList()->GetRootObject(lastClassCode);
		}

		

		Void SetTitle(List<Object^>^ query)
		{
			_tables = gcnew List<String ^>();

			int nCount = -1;
			for each(Object^ o in query)
			{
				String^ table = o->ToString();
				if	(!String::IsNullOrEmpty(table))
				{
					_tables->Add(table);
				}

				if (table->Length > nCount)
				{
					_title = table;
					nCount = table->Length;
				}
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
			SemanticPosition^ rootPos = gcnew SemanticPosition(_root, _attributes, _attrId, BookSetting);
			return GetChildPositions(rootPos->GetChildPositions());

		}

		List<Position^>^ GetMaxLevelPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs ^ e)
		{
			SemanticPosition^ rootPos = gcnew SemanticPosition(_root, _attributes, _attrId, BookSetting);
			return GetChildPositions2(rootPos->GetChildPositions(), worker, e);

		}

		void CheckGroups(Dictionary<Attribute^, String^>^ attrsAndNewVals)
		{
			SortTables();
			/*for each (String^ table in _tables)
			{
				Dictionary<Attribute^, String^>^ tableAttrs = gcnew Dictionary<Attribute^, String^>();
				for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
				{
					if	(pair->Key->FullTable == table)
					{
						tableAttrs->Add(pair->Key, pair->Value);
					}
					if	(!Contains(tableAttrs, table))
					{
						AddCurrentLevelPosition(_tables, attrsAndNewVals);
					}
				}
			}*/
			AddCurrentLevelPosition(_tables, attrsAndNewVals);
		}

		bool Contains(Dictionary<Attribute^, String^>^ tableAttrs, String^ table)
		{
			return false;
		}

		void SortTables()
		{
			List<String^>^ list = gcnew List<String^>();
			for each (String^ table in _tables)
			{
				if	(list->Count <= 0)
				{
					list->Add(table);
				}
				else
				{
					for (int i = 0; i < list->Count; i++)
					{
						if (list[i]->Length > table->Length)
						{
							list->Insert(i, table);
						}
						else
						{
							list->Add(table);
						}
						break;
					}
				}
			}
			list->RemoveAt(list->Count - 1);
			_tables = list;
		}

		String^ GetMaxLengthTable(Dictionary<Attribute^, String^>^ attrsAndNewVals)
		{
			String^ table = String::Empty;
			for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
			{
				if	(pair->Key->FullTable->Length > table->Length)
				{
					table = pair->Key->FullTable;
				}
			}
			return table;
		}

		void AddCurrentLevelPosition(List<String^>^ table, Dictionary<Attribute^, String^>^ attrsAndNewVals)
		{
			_attrNewVals = attrsAndNewVals;

			array<String^, 1>^ fullCode = table[0]->Split('.');
			Dictionary<Attribute^, String^>^ groupAttrsList = gcnew Dictionary<Attribute^, String^>();
			for each(KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
			{
				if	(pair->Key->FullTable == table[0])
				{
					groupAttrsList->Add(pair->Key, pair->Value);
				}
			}

			ISCObject^ root = _semantic->Core->ObjectList()->GetRootObject(fullCode[1]);
			ISCObject^ cla = root;

			SCChildList^ childList = GetChildListToAdd(cla, groupAttrsList, 1);
			AddNewObject(childList);
		}

		SCChildList^ GetChildListToAdd(ISCObject^ cla, Dictionary<Attribute^, String^>^ groupAttrsList, int nTable)
		{
			SCChildList^ childList;
			int nChList = cla->ChildListCount();
			childList = cla->ChildListByIdx(0);
			int nObjs = childList->CountChildObjects;
			for (int j = 0; j < nObjs; j++)
			{
				//проверка
				cla = childList->ChildObjects[j];
				if (HasSimilarAttrs(cla, groupAttrsList))
				{
					if	(nTable >= _tables->Count)
					{
						return cla->ChildListByIdx(0);
					}

					Dictionary<Attribute^, String^>^ groupAttrsList = gcnew Dictionary<Attribute^, String^>();
					for each(KeyValuePair<Attribute^, String^>^ pair in _attrNewVals)
					{
						Attribute^ attr = pair->Key;
						if	(attr->FullTable == _tables[nTable])
						{
							groupAttrsList->Add(attr, pair->Value);
						}
					}
					nTable++;

					SCChildList^ childListNew = GetChildListToAdd(cla, groupAttrsList, nTable);
					return childListNew;

				}
			}
			cla = AddNewObject(childList);

			if	(nTable >= _tables->Count)
			{
				return cla->ChildListByIdx(0);
			}

			Dictionary<Attribute^, String^>^ groupAttrsList1 = gcnew Dictionary<Attribute^, String^>();
			for each(KeyValuePair<Attribute^, String^>^ pair in _attrNewVals)
			{
				Attribute^ attr = pair->Key;
				if	(attr->FullTable == _tables[nTable])
				{
					groupAttrsList1->Add(attr, pair->Value);
				}
			}
			nTable++;

			SCChildList^ childListNew = GetChildListToAdd(cla, groupAttrsList1, nTable);
			return childListNew;
		}

		ISCObject^  AddNewObject(SCChildList^ childList)
		{
			String^ newGuid = _semantic->Core->Settings()->GetGUID22();
			ISCObject^ obb = childList->AddChildObject(newGuid);

			obb->BeginUpdate();
			for each(KeyValuePair<Attribute^, String^>^ pair in _attrNewVals)
			{
				ISCAttribute^ attr = obb->AttrObjectByNameAttr(pair->Key->Code);
				if	(attr != nullptr)
				{
					attr->DataAttr = pair->Value;
				}
			}
			obb->EndUpdate();
			return obb;
		}

		bool HasSimilarAttrs(ISCObject^ group, Dictionary<Attribute^, String^>^ attrsAndNewVals)
		{
			bool similar = true;
			for each(KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
			{
				Attribute^ attrib = pair->Key;
				ISCAttribute^ attr = group->AttrObjectByNameAttr(attrib->Code);
				String^ value = pair->Value;
				if	(attr != nullptr && attr->DataAttr->ToString() != value)
				{
					similar = false;
					break;
				}
			}
			return similar;
		}
	};
}