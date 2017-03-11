#pragma once

#include "Book.h"
#include "DbPosition.h"
#include "Position.h"
#include "IntegrationSettings.h"
#include "Results2.h"
#include "ODBCclass.h"
#include "Editting.h"
#include "DbFilter.h"

namespace Integra {

	using namespace System::Collections::Generic;

	/// <summary>
	/// Класс spravochnika Semantic
	/// </summary>
	public ref class DbBook : Book
	{

	private:
		Attribute^ _equivAttr;
		bool _isSource;

		List<Attribute^>^ _attributes;

		bool _WHEREisSet;

	public:
		DbBook(BookSettings^ bookSettings, IntegrationSettings^ intSettings, bool isSource, OdbcClass^ odbc) : Book(bookSettings, intSettings, odbc)
		{
			_isSource = isSource;
			if (intSettings != nullptr)
			{
				if (_isSource)
				{
					_attributes = _intSettings->SimpleSourceAttributes;
					_equivAttr = _intSettings->SourceEquivAttr;
				} 
				else
				{
					_attributes = _intSettings->SimpleTargetAttributes;
					_equivAttr = _intSettings->TargetEquivAttr;
				}
			}
			
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbBook() 
		{

		}

	public:
		virtual List<Position^>^ GetAllPositions() override
		{
			List<Position^>^ list = gcnew List<Position ^>();
			List<Object^>^ query = _odbc->ExecuteQuery("select " + _equivAttr->Code + " from " + _equivAttr->FullTable + " order by " + _equivAttr->Code);
			for each (Object^ o in query)
			{
				String^ sId = o->ToString();
				int number;
				bool result = Int32::TryParse(sId, number);
				Position^ pos = gcnew DbPosition(sId, _equivAttr, _attributes, _odbc, BookSetting);
				list->Add(pos);
			}

			return list;
		}

		virtual List<Position^>^ GetAllPositionsTable(List<Attribute^>^ attrs, List<Object^>^ filters, List<Object^>^ links) override
		{
			String^ globalSquery = GetGlobalSquery(nullptr, String::Empty, String::Empty, attrs, filters, links);

	
			int iId = -1, iTitle = -1;
			bool idSet = false;
			bool titleSet = false;
			for (int i = 0; i < attrs->Count; i++)
			{
				if (!idSet && attrs[i]->FullCode == BookSetting->AttrIdFullcode)
				{
					iId = i;
					idSet = true;
				}
				if (!titleSet && attrs[i]->FullCode == BookSetting->AttrTitleFullcode)
				{
					iTitle = i;
					titleSet = true;
				}
				if (idSet && titleSet)
				{
					break;
				}
			}
			
 			List<Object^>^ table = BookSetting->Odbc->ExecuteQuery(globalSquery);
			List<Position^>^ poses = gcnew List<Position ^>();
			for (int i = 0; i < table->Count; i+=attrs->Count)
			{
				List<Object^>^ attrValues = table->GetRange(i, attrs->Count);
				Position^ pos = gcnew DbPosition(attrValues, attrs, iId, iTitle, BookSetting);
				poses->Add(pos);
			}

 			return poses;
		}

		virtual List<Position^>^ GetGroupPositionsTable(Attribute^ groupAttr, String^ dbGroupId, String^ groupFullTable, List<Attribute^>^ attrs, List<Object^>^ filters, List<Object^>^ links) override
		{
			String^ globalSquery = GetGlobalSquery(groupAttr, dbGroupId, groupFullTable, attrs, filters, links);

			int iId = -1, iTitle = -1;
			bool idSet = false;
			bool titleSet = false;
			for (int i = 0; i < attrs->Count; i++)
			{
				if (!idSet && attrs[i]->FullCode == BookSetting->AttrIdFullcode)
				{
					iId = i;
					idSet = true;
				}
				if (!titleSet && attrs[i]->FullCode == BookSetting->AttrTitleFullcode)
				{
					iTitle = i;
					titleSet = true;
				}
				if (idSet && titleSet)
				{
					break;
				}
			}

			List<Object^>^ table = BookSetting->Odbc->ExecuteQuery(globalSquery);
			List<Position^>^ poses = gcnew List<Position ^>();
			for (int i = 0; i < table->Count; i+=attrs->Count)
			{
				List<Object^>^ attrValues = table->GetRange(i, attrs->Count);
				Position^ pos = gcnew DbPosition(attrValues, attrs, iId, iTitle, BookSetting);
				poses->Add(pos);
			}

			return poses;
		}

		virtual Dictionary<String^, String^>^ GetAllGroupNames() override
		{
			String^ squery = String::Format("select IAA.SCHEMA_NAME, IAA.TABLE_NAME, IAA.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA, {0}INTEGRATION_BOOK IBB, {0}GROUP_PARAMS GPP " + 
				"where IBB.ID = {1} and IBB.GROUP_ID = GPP.ID and GPP.NAME_ATTR = IAA.ID", _odbc->schema, BookSetting->Id);
			List<Object^>^ list1 = BookSetting->Odbc->ExecuteQuery(squery);
			String^ grAttrSchema = list1[0]->ToString();
			String^ grAttrTable = list1[1]->ToString();
			String^ grAttrCode = list1[2]->ToString();

			squery = String::Format("select IAA.SCHEMA_NAME, IAA.TABLE_NAME, IAA.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IAA, {0}INTEGRATION_BOOK IBB, {0}GROUP_PARAMS GPP " + 
				"where IBB.ID = {1} and IBB.GROUP_ID = GPP.ID and GPP.ID_ATTR = IAA.ID", _odbc->schema, BookSetting->Id);
			list1 = BookSetting->Odbc->ExecuteQuery(squery);
			String^ grIdAttrSchema = list1[0]->ToString();
			String^ grIdAttrTable = list1[1]->ToString();
			String^ grIdAttrCode = list1[2]->ToString();

			if (!String::IsNullOrEmpty(grIdAttrSchema))
			{
				grIdAttrSchema += ".";
			}

			squery = String::Format("select {0}{1}.{2}, {3}{4}.{5} from {0}{1}", grIdAttrSchema, grIdAttrTable, grIdAttrCode, grAttrSchema, grAttrTable, grAttrCode);
			List<Object^>^ list2 = BookSetting->Odbc->ExecuteQuery(squery);
			Dictionary<String^, String^>^ resList = gcnew Dictionary<String^, String^>();
			for (int i = 0; i < list2->Count; i+=2)
			{
				resList->Add(list2[i]->ToString(), list2[i+1]->ToString());
			}
			return resList;
		}

		virtual Object^ GetGroupAttrValue(Attribute^ attribute, String^ idGroup) override
		{
			Attribute^ groupIdAttr = BookSetting->AttrGroupId;
			String^ sIdGroup = BookSetting->Odbc->GetSqlValue(groupIdAttr->DataType, idGroup);

			String^ squery = String::Format("select {0} from {1} where {2} = {3}", attribute->FullCode, attribute->FullTable, groupIdAttr->FullCode, sIdGroup);
			List<Object^>^ list2 = BookSetting->Odbc->ExecuteQuery(squery);
			return list2[0];
		}

		virtual Object^ GetPosAttrValue(Attribute^ attribute, String^ idPos) override
		{
			Attribute^ posIdAttr = BookSetting->AttrId;
			String^ sIdPos = BookSetting->Odbc->GetSqlValue(posIdAttr->DataType, idPos);

			String^ squery = String::Format("select {0} from {1} where {2} = {3}", attribute->FullCode, attribute->FullTable, posIdAttr->FullCode, sIdPos);
			List<Object^>^ list2 = BookSetting->Odbc->ExecuteQuery(squery);
			return list2[0];
		}

		virtual List<Position^>^ GetAllPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) override
		{
			List<Position^>^ list = gcnew List<Position ^>();
			String^ strQuery = "select ";
			int nAttr = _attributes->Count;
			int iId;
			String^ codeId;
			Attribute^ attrId;
			for (int i = 0; i < nAttr; i++)
			{
				strQuery += String::Format("{0}.{1}, ", _attributes[i]->FullTable, _attributes[i]->Code);
				if (_attributes[i]->Code == _equivAttr->Code)
				{
					iId = i;
					codeId = _attributes[i]->Code;
					attrId = _attributes[i];
				}
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += " from ";

			List<Object^>^ titleList;
			if (_isSource)
			{
				titleList = GetSourceTitle();
			}
			else
			{
				titleList = GetTargetTitle();
			}

			int n = titleList->Count;
			for (int i = 0; i < n; i++)
			{
				strQuery += String::Format("{0}, ", titleList[i]->ToString());
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += String::Format(" order by {0}.{1}", _equivAttr->FullTable, _equivAttr->Code);

			List<Object^>^ query = BookSetting->Odbc->ExecuteQuery(strQuery);

			if ( worker->CancellationPending )
			{
				e->Cancel = true;
			}
			else
			{
				n = query->Count;
				for (int i = 0; i < n; i += nAttr)
				{
					Dictionary<Attribute^, String^>^ dic = gcnew Dictionary<Attribute ^, String ^>();
					for (int j = 0; j < nAttr; j++)
					{
						dic->Add(_attributes[j], query[i+j]->ToString());
					}
					String^ sId = query[i+iId]->ToString();
					Position^ pos = gcnew DbPosition(sId, attrId, _attributes, dic, BookSetting);
					list->Add(pos);
					worker->ReportProgress(i/nAttr, nullptr);

					if ( worker->CancellationPending )
					{
						e->Cancel = true;
						break;
					}
				}
			}
			return list;
		}

		virtual List<Position^>^ GetAllPositions22(int% nc) override
		{
			List<Position^>^ list = gcnew List<Position ^>();
			String^ strQuery = "select ";
			int nAttr = _attributes->Count;
			int iId;
			String^ codeId;
			Attribute^ attrId;
			for (int i = 0; i < nAttr; i++)
			{
				strQuery += String::Format("{0}.{1}, ", _attributes[i]->FullTable, _attributes[i]->Code);
				if (_attributes[i]->Code == _equivAttr->Code)
				{
					iId = i;
					codeId = _attributes[i]->Code;
					attrId = _attributes[i];
				}
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += " from ";

			List<Object^>^ titleList;
			if (_isSource)
			{
				titleList = GetSourceTitle();
			}
			else
			{
				titleList = GetTargetTitle();
			}

			int n = titleList->Count;
			for (int i = 0; i < n; i++)
			{
				strQuery += String::Format("{0}, ", titleList[i]->ToString());
			}
			strQuery = strQuery->Substring(0, strQuery->Length - 2);
			strQuery += String::Format(" order by {0}.{1}", _equivAttr->FullTable, _equivAttr->Code);

			List<Object^>^ query = BookSetting->Odbc->ExecuteQuery(strQuery);

				n = query->Count;
				for (int i = 0; i < n; i += nAttr)
				{
					Dictionary<Attribute^, String^>^ dic = gcnew Dictionary<Attribute ^, String ^>();
					for (int j = 0; j < nAttr; j++)
					{
						dic->Add(_attributes[j], query[i+j]->ToString());
					}
					String^ sId = query[i+iId]->ToString();
					Position^ pos = gcnew DbPosition(sId, attrId, _attributes, dic, BookSetting);
					list->Add(pos);
				}

				nc = n/nAttr;
			return list;
		}

		virtual void AddPosition(Dictionary<Attribute^, String^>^ attrsAndNewVals, Object^ idVal, Object^ titleVal, IntegrationResult^ result, int isTarget) override
		{
			List<String^>^ queres = gcnew List<String ^>();
			if (BookSetting->DbLinks != nullptr && BookSetting->DbLinks->Count > 0)
			{
				List<String^>^ linkQueres = AddPositonsOnLink(attrsAndNewVals, idVal);
				queres->AddRange(linkQueres);
			}
			else
			{
				String^ table;
				List<String^>^ valueList = gcnew List<String ^>();
				List<String^>^ titleList = gcnew List<String ^>();

				for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
				{
					titleList->Add(pair->Key->Code);
					if (String::IsNullOrEmpty(table))
					{
						table = pair->Key->FullTable;
					}
					valueList->Add(BookSetting->Odbc->GetSqlValue(pair->Key->DataType, pair->Value));
				}

				String^ squery = String::Format("insert into {0} (", table);
				bool isSetAttrId = false;
				for each (String^ title in titleList)
				{
					if (title == BookSetting->AttrId->Code)
					{
						isSetAttrId = true;
					}
					squery += String::Format("{0},", title);
				}
				if (!isSetAttrId)
				{
					squery += String::Format("{0},", BookSetting->AttrId->Code);
				}

				squery = squery->Substring(0, squery->Length - 1);
				squery += ") values (";
				for each (String^ val in valueList)
				{
					squery += String::Format("{0},", val);
				}
				if (!isSetAttrId)
				{
					squery += String::Format("{0},", BookSetting->Odbc->GetSqlValue(BookSetting->AttrId->DataType, idVal->ToString()));
				}

				squery = squery->Substring(0, squery->Length - 1);
				squery += ")";
				queres->Add(squery);
			}

			for each (String^ quer in queres)
			{
				try
				{
					BookSetting->Odbc->ExecuteNonQuery(quer);
				}
				catch (Exception^ e)
				{
					throw e;
				}
				Editting^ newEdit = gcnew Editting(_odbc, result, 0, isTarget, idVal->ToString(), titleVal->ToString());
				newEdit->WriteNewPos();
			}

			
		}

		virtual void UpdatePosition(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals) override
		{
			String^ table;
			String^ squery = "update ";
			for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
			{
				if (String::IsNullOrEmpty(table))
				{
					table = pair->Key->FullTable;
					squery += String::Format("{0} set", table);
				}
				String^ value;
				if (pair->Key->DataType == "СТРОКА")
				{
					value = OdbcClass::GetSqlString(pair->Value);
				}
				else
				{
					value = pair->Value;
				}
				squery += String::Format(" {0} = {1},", pair->Key->FullCode, value);
			}
			squery = squery->Substring(0, squery->Length - 1);
			squery += String::Format(" where {0} = {1}", currentPos->AttrId->Code, OdbcClass::GetSqlString(currentPos->UnicId));
			BookSetting->Odbc->ExecuteNonQuery(squery);
		}

		virtual void UpdatePositionForEachAttr(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals, IntegrationResult^ result, int isTarget) override
		{
			for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
			{
				Attribute^ attr = pair->Key;
				String^ attrVal = pair->Value;

				String^ table = attr->FullTable;
				String^ squery = String::Format("update {0} set", table);


				String^ strValueAttr = BookSetting->Odbc->GetSqlValue(attr->DataType, attrVal);
				squery += String::Format(" {0} = {1},", attr->FullCode, strValueAttr);
				squery = squery->Substring(0, squery->Length - 1);


				Attribute^ whereAttr = GetAttrLinkId(table);
				if (whereAttr == nullptr)
				{
					whereAttr = currentPos->AttrId;
				}
				strValueAttr = BookSetting->Odbc->GetSqlValue(whereAttr->DataType, currentPos->UnicId);
				squery += String::Format(" where ({0} = {1})", whereAttr->FullCode, strValueAttr);

				try
				{
					BookSetting->Odbc->ExecuteNonQuery(squery);
				}
				catch (Exception^ e)
				{
					throw e;
				}
				Editting^ newEdit = gcnew Editting(_odbc, result, 1, isTarget, currentPos->UnicId, attr, currentPos->GetValue(attr), attrVal);
				newEdit->WriteEditingPos();
				
			}
			
		}

		virtual Object^ GetSemObject(String^ location) override
		{
			return nullptr;
		}

		private:

			List<String^>^ AddPositonsOnLink(Dictionary<Attribute^, String^>^ attrsAndNewVals, Object^ idVal)
			{
				List<Attribute^>^ tableAttrs = gcnew List<Attribute ^>();
				for each (DbLink^ link in BookSetting->DbLinks)
				{
					Attribute^ attr1 = link->Attribute1;
					if (!tableAttrs->Contains(attr1))
					{
						tableAttrs->Add(attr1);
					}
					Attribute^ attr2 = link->Attribute2;
					if (!tableAttrs->Contains(attr2))
					{
						tableAttrs->Add(attr2);
					}
				}
				List<String^>^ queres = gcnew List<String ^>();
				for each (Attribute^ attr in tableAttrs)
				{
					List<String^>^ valueList = gcnew List<String ^>();
					List<Attribute^>^ titleList = gcnew List<Attribute ^>();

					String^ query = String::Format("insert into {0} (", attr->FullTable);
					for each (KeyValuePair<Attribute^, String^>^ pairAttrNewVal in attrsAndNewVals)
					{
						if (pairAttrNewVal->Key->FullTable == attr->FullTable)
						{
							titleList->Add(pairAttrNewVal->Key);
							valueList->Add(BookSetting->Odbc->GetSqlValue(pairAttrNewVal->Key->DataType, pairAttrNewVal->Value));
						}
					}
					if	(titleList->Count <= 0)
					{
						continue;
					}

					bool isSetAttrId = false;
					for each (Attribute^ title in titleList)
					{
						if (title->Code == attr->Code)
						{
							isSetAttrId = true;
						}
						query += String::Format("{0},", title->Code);
					}
					if (!isSetAttrId)
					{
						query += String::Format("{0},", attr->Code);
					}

					query = query->Substring(0, query->Length - 1);
					query += ") values (";
					for (int i = 0; i < valueList->Count; i++)
					{
						query += String::Format("{0},", valueList[i]);
					}
					if (!isSetAttrId)
					{
						query += String::Format("{0},", BookSetting->Odbc->GetSqlValue(attr->DataType, idVal->ToString()));
					}

					query = query->Substring(0, query->Length - 1);
					query += ")";

					queres->Add(query);
				}
				return queres;
			}

			Attribute^ GetAttrLinkId(String^ fullTable)
			{
				if (BookSetting->DbLinks == nullptr || BookSetting->DbLinks->Count <= 0)
				{
					return nullptr;
				}

				for each (DbLink^ link in BookSetting->DbLinks)
				{
					if (link->Attribute1->FullTable == fullTable)
					{
						return link->Attribute1;
					}
					if (link->Attribute2->FullTable == fullTable)
					{
						return link->Attribute2;
					}
				}
				return nullptr;
			}

			List<Object^>^ GetTableCodeAttrs()
			{
				String^ squery = String::Format("select IA.FULL_CODE, IA.ATTR_NAME, IA.NAME from {0}INTEGRATION_ATTRIBUTES IA, {0}INTEGRATION_BOOK IB where " +
					"IB.ID = {1} and IA.ID_INTGR_BOOK = IB.ID", _odbc->schema, BookSetting->Id);
				return _odbc->ExecuteQuery(squery);
			}

			List<String^>^ GetTables(List<Object^>^ tableCodeAttrs)
			{
				List<String^>^ list = gcnew List<String ^>();
				for (int i = 0; i < tableCodeAttrs->Count; i += 3)
				{
					if (!list->Contains(tableCodeAttrs[i]->ToString()))
					{
						list->Add(tableCodeAttrs[i]->ToString());
					}
				}
				return list;
			}

			List<Attribute^>^ GetAttrsName(List<Object^>^ tableCodeAttrs)
			{
				List<Attribute^>^ list = gcnew List<Attribute ^>();
				for (int i = 0; i < tableCodeAttrs->Count; i += 3)
				{
					String^ fullTable = tableCodeAttrs[i]->ToString();
					String^ code = tableCodeAttrs[i+1]->ToString();
					String^ name = tableCodeAttrs[i+2]->ToString();
					Attribute^ attr = gcnew Attribute(fullTable, code, name);
					if (!list->Contains(attr))
					{
						list->Add(attr);
					}
				}
				return list;
			}

			String^ GetGlobalSquery(Attribute^ groupAttr, String^ dbGroupId, String^ groupFullTable, List<Attribute^>^ attrNames, List<Object^>^ filters, List<Object^>^ links)
			{
				String^ s = "select ";
				String^ tableFirstAttr;
				for each (Attribute^ attr in attrNames)
				{
					if (attr->FullTable != groupFullTable)
					{
						s += attr->FullCode + ",";
						if (String::IsNullOrEmpty(tableFirstAttr))
						{
							tableFirstAttr = attr->FullTable;
						}
					}
				}
				s = s->Substring(0, s->Length - 1);

				_WHEREisSet = false;
				s = SetTables(s, tableFirstAttr, links);
				s = SetFiltersAndLinks(s, filters, links);
				s = SetGroup(s, groupAttr, dbGroupId);

				return s;
			}

			String^ SetFiltersAndLinks(String^ squery, List<Object^>^ filters, List<Object^>^ links)
			{
				bool hasFilters = false;
				if (filters != nullptr && filters->Count > 0)
				{
					squery += " where ";
					squery = SetFilters(squery, filters);
					hasFilters = true;
					_WHEREisSet = true;
				}
				if (links != nullptr && links->Count > 0)
				{
					if (hasFilters)
					{
						squery += " AND ";
					}
					else
					{
						squery += " where ";
					}
					squery = SetLinks(squery, links);
					_WHEREisSet = true;
				}
				return squery;
			}

			String^ SetTables(String^ squery, String^ attrFullTable, List<Object^>^ links)
			{
				squery += " from ";
				if (links != nullptr && links->Count > 0)
				{
					List<String^>^ fullTables = gcnew List<String ^>();
					for each (DbLink^ link in links)
					{
						String^ fullTable1 = link->Attribute1->FullTable;
						if (!fullTables->Contains(fullTable1))
						{
							fullTables->Add(fullTable1);
						}
						String^ fullTable2 = link->Attribute2->FullTable;
						if (!fullTables->Contains(fullTable2))
						{
							fullTables->Add(fullTable2);
						}
					}
					for each (String^ fullTable in fullTables)
					{
						squery += String::Format("{0},", fullTable);
					}
					squery = squery->Substring(0, squery->Length - 1);
				}
				else
				{
					squery += attrFullTable;
				}
				return squery;
			}

			String^ SetFilters(String^ squery, List<Object^>^ filters)
			{
				if (filters != nullptr && filters->Count > 0)
				{
					squery += "(";
					String^ prevConcatValue = String::Empty;
					for each (DbFilter^ filter in filters)
					{
						String^ sVal = _odbc->GetSqlValue(filter->AttributeDataType, filter->ConditionValue);
						String^ line = String::Format("{0} {1} {2} {3} ", prevConcatValue, filter->AttributeFullCode, filter->Condition, sVal);
						squery += line;
						prevConcatValue = filter->ConcatinationValue;
					}
					squery = String::Format("{0})", squery);
					_WHEREisSet = true;
				}
				return squery;
			}

			String^ SetLinks(String^ squery, List<Object^>^ links)
			{
				if (links != nullptr && links->Count > 0)
				{
					squery += "(";
					String^ sAnd = "";
					for each (DbLink^ link in links)
					{
						String^ line = String::Format(" {0} {1} = {2}", sAnd, link->Attribute1->FullCode, link->Attribute2->FullCode);
						squery += line;
						sAnd = "AND";
					}
					squery = String::Format("{0})", squery);
					_WHEREisSet = true;
				}
				return squery;
			}
			
			String^ SetGroup(String^ squery, Attribute^ groupAttr, String^ dbGroupId)
			{
				if (groupAttr != nullptr)
				{
					if (_WHEREisSet)
					{
						squery += " and ";
					}
					else
					{
						squery += " where ";
					}
					squery += String::Format("{0} = {1}", groupAttr->Code, _odbc->GetSqlValue(groupAttr->DataType, dbGroupId));
				}
				return squery;
			}
	};
}