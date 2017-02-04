#pragma once

#include "Book.h"
#include "DbPosition.h"
#include "Position.h"
#include "IntegrationSettings.h"
#include "Results2.h"
#include "ODBCclass.h"
#include "Editting.h"

namespace Integra {

	using namespace System::Collections::Generic;

	/// <summary>
	/// ����� spravochnika Semantic
	/// </summary>
	public ref class DbBook : Book
	{

	private:
		Attribute^ _equivAttr;
		bool _isSource;

		List<Attribute^>^ _attributes;

	public:
		DbBook(BookSettings^ bookSettings, IntegrationSettings^ intSettings, bool isSource, OdbcClass^ odbc) : Book(bookSettings, intSettings, odbc)
		{
			_isSource = isSource;
			if (_isSource)
			{
				_attributes = intSettings->SourceAttributes;
				_equivAttr = _intSettings->SourceEquivAttr;
			} 
			else
			{
				_attributes = intSettings->TargetAttributes;
				_equivAttr = _intSettings->TargetEquivAttr;
			}
		}


	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
				Position^ pos = gcnew DbPosition(sId, _equivAttr->Code, _attributes, _odbc);
				list->Add(pos);
			}

			return list;
		}

		virtual List<Position^>^ GetAllPositionsTable(List<Attribute^>^ attrs) override
		{
			String^ globalSquery = GetGlobalSquery(attrs);

// 			List<Object^>^ tableCodeAttrs = GetTableCodeAttrs();
// 			List<String^>^ tables = GetTables(tableCodeAttrs);
// 			attrNames = GetAttrsName(tableCodeAttrs);
// 			
			int iId, iTitle;
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
				Position^ pos = gcnew DbPosition(attrValues, attrs, iId, iTitle);
				poses->Add(pos);
			}

 			return poses;
		}

		


		virtual List<Position^>^ GetAllPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) override
		{
			List<Position^>^ list = gcnew List<Position ^>();
			String^ strQuery = "select ";
			int nAttr = _attributes->Count;
			int iId;
			String^ codeId;
			for (int i = 0; i < nAttr; i++)
			{
				strQuery += String::Format("{0}.{1}, ", _attributes[i]->FullTable, _attributes[i]->Code);
				if (_attributes[i]->Code == _equivAttr->Code)
				{
					iId = i;
					codeId = _attributes[i]->Code;
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

			List<Object^>^ query = _odbc->ExecuteQuery(strQuery);

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
					Position^ pos = gcnew DbPosition(sId, codeId, _attributes, dic);
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
			for (int i = 0; i < nAttr; i++)
			{
				strQuery += String::Format("{0}.{1}, ", _attributes[i]->FullTable, _attributes[i]->Code);
				if (_attributes[i]->Code == _equivAttr->Code)
				{
					iId = i;
					codeId = _attributes[i]->Code;
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

			List<Object^>^ query = _odbc->ExecuteQuery(strQuery);

				n = query->Count;
				for (int i = 0; i < n; i += nAttr)
				{
					Dictionary<Attribute^, String^>^ dic = gcnew Dictionary<Attribute ^, String ^>();
					for (int j = 0; j < nAttr; j++)
					{
						dic->Add(_attributes[j], query[i+j]->ToString());
					}
					String^ sId = query[i+iId]->ToString();
					Position^ pos = gcnew DbPosition(sId, codeId, _attributes, dic);
					list->Add(pos);
				}

				nc = n/nAttr;
			return list;
		}

		virtual void AddPosition(Dictionary<Attribute^, String^>^ attrsAndNewVals) override
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
				if (pair->Key->DataType == "������")
				{
					valueList->Add(OdbcClass::GetSqlString(pair->Value));
				}
				else
				{
					valueList->Add(pair->Value);
				}
			}

			String^ squery = String::Format("insert into {0} (", table);
			for each (String^ title in titleList)
			{
				squery += String::Format("{0},", title);
			}
			squery = squery->Substring(0, squery->Length - 1);
			squery += ") values (";
			for each (String^ val in valueList)
			{
				squery += String::Format("{0},", val);
			}
			squery = squery->Substring(0, squery->Length - 1);
			squery += ")";

			BookSetting->Odbc->ExecuteNonQuery(squery);
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
				if (pair->Key->DataType == "������")
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
			squery += String::Format(" where {0} = {1}", currentPos->AttrIdCode, OdbcClass::GetSqlString(currentPos->UnicId));
			BookSetting->Odbc->ExecuteNonQuery(squery);
		}

		virtual void UpdatePositionForEachAttr(Position^ currentPos, Dictionary<Attribute^, String^>^ attrsAndNewVals, IntegrationResult^ result, int isTarget) override
		{
			for each (KeyValuePair<Attribute^, String^>^ pair in attrsAndNewVals)
			{
				Attribute^ attr = pair->Key;
				String^ attrVal = pair->Value;

				String^ table;
				String^ squery = "update ";
				if (String::IsNullOrEmpty(table))
				{
					table = attr->FullTable;
					squery += String::Format("{0} set", table);
				}
				String^ value;
				if (attr->DataType == "������")
				{
					value = OdbcClass::GetSqlString(attrVal);
				}
				else
				{
					value = attrVal;
				}
				squery += String::Format(" {0} = {1},", attr->FullCode, value);
				squery = squery->Substring(0, squery->Length - 1);
				squery += String::Format(" where {0} = {1}", currentPos->AttrIdCode, OdbcClass::GetSqlString(currentPos->UnicId));
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

		private:
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

			String^ GetGlobalSquery(List<Attribute^>^ attrNames)
			{
				String^ s = "select ";
				for each (Attribute^ attr in attrNames)
				{
					s += attr->FullCode + ",";
				}
				s = s->Substring(0, s->Length - 1);
				s += " from ";
				s += attrNames[0]->FullTable;

				return s;
			}
	};
}