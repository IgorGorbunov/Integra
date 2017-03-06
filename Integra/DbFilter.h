#pragma once

#include "ODBCclass.h"
#include "Attribute.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class DbFilter 
	{
	public:
		property String^ AttributeFullCode
		{
			String^ get()
			{
				return _attribute->FullCode;
			}
		}
		property String^ AttributeDataType
		{
			String^ get()
			{
				return _attribute->DataType;
			}
		}

		property String^ Condition
		{
			String^ get()
			{
				return _condition;
			}
		}
		property String^ ConditionValue
		{
			String^ get()
			{
				return _condValue;
			}
		}
		property String^ ConcatinationValue
		{
			String^ get()
			{
				return _concatValue;
			}
		}

	private:
		OdbcClass^ _odbc;

		int _id;
		Attribute^ _attribute;
		String^ _condition;
		String^ _condValue;
		// 0 - and, 1 - or
		String^ _concatValue;

	public:

		DbFilter(Attribute^ attribute, String^ condition, String^ condValue, String^ concatValue, OdbcClass^ odbc)
		{
			_odbc = odbc;

			_attribute = attribute;
			_condition = condition;
			_condValue = condValue;
			_concatValue = concatValue;
		}

		DbFilter(int id, Attribute^ attribute, String^ condition, String^ condValue, String^ concatValue, OdbcClass^ odbc)
		{
			_id = id;
			_odbc = odbc;

			_attribute = attribute;
			_condition = condition;
			_condValue = condValue;
			_concatValue = concatValue;
		}

		static List<Object^>^ GetFilters(int integrationBookId, OdbcClass^ odbc)
		{
			List<Object^>^ list;
			String^ squery = "select DBF.ID,IAA.ID,IAA.NAME,IAA.SCHEMA_NAME,IAA.TABLE_NAME,IAA.ATTR_NAME,IAA.ID_INTGR_BOOK,IAA.DATA_TYPE,IAA.MAX_LENGTH,DBF.CONDITION,DBF.VALU,DBF.CONCAT_VALUE from " +
				"{0}DB_FILTERS DBF, {0}INTEGRATION_ATTRIBUTES IAA where DBF.ID_INTGR_BOOK = {1} and DBF.ATTR_ID = IAA.ID order by DBF.ID";
			squery = String::Format(squery, odbc->schema, integrationBookId);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				list = gcnew List<Object ^>();
				for (int i = 0; i < resList->Count; i+=12)
				{
					int filterId = odbc->GetResInt(resList[i+0]);
					int attrId = odbc->GetResInt(resList[i+1]);
					String^ attrName = resList[i+2]->ToString();
					String^ attrSchemaName = resList[i+3]->ToString();
					String^ attrTableName = resList[i+4]->ToString();
					String^ attrCode = resList[i+5]->ToString();
					int attrIntBookId = odbc->GetResInt(resList[i+6]);
					String^ attrDataType = resList[i+7]->ToString();
					int attrMaxLength = odbc->GetResInt(resList[i+8]);
					Attribute^ attr = gcnew Attribute(attrId, attrName, attrSchemaName, attrTableName, attrCode, attrIntBookId, attrDataType, attrMaxLength + "", odbc);

					String^ filterCondition = resList[i+9]->ToString();
					String^ filterConditionValue = resList[i+10]->ToString();
					int filterConcatValue = odbc->GetResInt(resList[i+11]);
					String^ sConcatValue = String::Empty;
					if (filterConcatValue == 0)
					{
						sConcatValue = "AND";
					}
					else if (filterConcatValue == 1)
					{
						sConcatValue = "OR";
					}
					DbFilter^ filter = gcnew DbFilter(filterId, attr, filterCondition, filterConditionValue, sConcatValue, odbc);
					list->Add(filter);
				}
			}

			return list;
		}

		void InsertToDb(int integrationBookId, int attrId)
		{
			_attribute->Id = attrId;
			InsertToDb(integrationBookId);
		}

		void InsertToDb(int integrationBookId)
		{
			String^ columns = "ID,ATTR_ID,CONDITION,VALU,ID_INTGR_BOOK,CREATE_USER,CREATE_DATE,CONCAT_VALUE";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			int id = _odbc->GetLastFreeId(_odbc->schema + "DB_FILTERS");
			
			int idAttr = _attribute->Id;
			String^ sCondition = OdbcClass::GetSqlString(_condition);
			String^ sCondValue = OdbcClass::GetSqlString(_condValue);
			int sConcatValue;
			if (_concatValue == "AND")
			{
				sConcatValue = 0;
			}
			else if (_concatValue == "OR")
			{
				sConcatValue = 1;
			}
			else
			{
				sConcatValue = -1;
			}

			String^ sQuery = String::Format("insert into {0}DB_FILTERS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8}, {9})",
				_odbc->schema, columns, id, idAttr, sCondition, sCondValue, integrationBookId, sqlUser, sqlDate, sConcatValue);
			_odbc->ExecuteNonQuery(sQuery);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbFilter() 
		{

		}


	};
}