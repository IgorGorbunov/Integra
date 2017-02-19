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