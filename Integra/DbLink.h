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
	public ref class DbLink 
	{
	public:
		property String^ Attribute1FullCode
		{
			String^ get()
			{
				return _firstAttribute->FullCode;
			}
		}
		property String^ Attribute2FullCode
		{
			String^ get()
			{
				return _secondAttribute->FullCode;
			}
		}

	private:
		OdbcClass^ _odbc;
		Attribute^ _firstAttribute;
		Attribute^ _secondAttribute;
		
		int _id;

	public:

		DbLink(Attribute^ firstAttribute, Attribute^ secondAttribute)
		{
			_firstAttribute = firstAttribute;
			_secondAttribute = secondAttribute;
		}

		void InsertToDb(OdbcClass^ odbc, int intgrBookId, int attr1Id, int attr2Id)
		{
			_odbc = odbc;
			_firstAttribute->Id = attr1Id;
			_secondAttribute->Id = attr2Id;

			String^ columns = "ID,ATTR_ID1,ATTR_ID2,ID_INTGR_BOOK,CREATE_USER,CREATE_DATE";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			_id = _odbc->GetLastFreeId(_odbc->schema + "DB_LINKS");

			String^ sQuery = String::Format("insert into {0}DB_LINKS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
				_odbc->schema, columns, _id, attr1Id, attr2Id, intgrBookId, sqlUser, sqlDate);
			_odbc->ExecuteNonQuery(sQuery);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbLink() 
		{

		}


	};
}