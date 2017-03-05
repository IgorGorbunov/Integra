#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class PosGroupParam 
	{
	public:
		property Attribute^ Attribute1
		{
			Attribute^ get()
			{
				return _attr1;
			}
		}
		property Attribute^ Attribute2
		{
			Attribute^ get()
			{
				return _attr2;
			}
		}


	private:
		OdbcClass^ _odbc;
		int _id;
		int _idIntegrationBook;

		Attribute^ _attr1;
		Attribute^ _attr2;


	public:

		PosGroupParam(Attribute^ attr1, Attribute^ attr2)
		{
			_attr1 = attr1;
			_attr2 = attr2;
		}

		void InsertToDb(OdbcClass^ odbc, int intgrBookId, int attr1Id, int attr2Id)
		{
			_odbc = odbc;
			_attr1->Id = attr1Id;
			_attr2->Id = attr2Id;

			String^ columns = "ID,ID_TITLE,ID_VALUE,ID_INTEGRATION_BOOK,CREATE_USER,CREATE_DATE";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			_id = _odbc->GetLastFreeId(_odbc->schema + "POSITION_GROUP_ATTRIBUTE_PAIRS");

			String^ sQuery = String::Format("insert into {0}POSITION_GROUP_ATTRIBUTE_PAIRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
				_odbc->schema, columns, _id, attr1Id, attr2Id, intgrBookId, sqlUser, sqlDate);
			_odbc->ExecuteNonQuery(sQuery);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PosGroupParam() 
		{

		}

	private:

	};
}