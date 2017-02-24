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
	public ref class Editting 
	{
	public:


	private:
		OdbcClass^ _odbc;

		int _id;
		IntegrationResult^ _result;
		// 0 - add, 1 - edit, 2 - delete
		int _type;
		Object^ _idPos;
		// 0 - source, 1 - target
		int _nSystem;
		DateTime^ _editDate;
		Attribute^ _attr;
		Object^ _oldValue;
		Object^ _newValue;
		


		String^ _createUser;
		DateTime^ _createDate;
		String^ _updateUser;
		DateTime^ _updateDate;

	public:

		Editting(OdbcClass^ odbc, IntegrationResult^ result, int type, int nSystem, Object^ idPos)
		{
			_odbc = odbc;
			_result = result;
			_type = type;
			_nSystem = nSystem;
			_idPos = idPos;
		}

		Editting(OdbcClass^ odbc, IntegrationResult^ result, int type, int nSystem, Object^ idPos, Attribute^ attr, Object^ oldVal, Object^ newVal)
		{
			_odbc = odbc;
			_result = result;
			_type = type;
			_nSystem = nSystem;
			_idPos = idPos;
			_attr = attr;
			_oldValue = oldVal;
			_newValue = newVal;
		}

		void WriteNewPos()
		{
			_editDate = DateTime::Now;
			_attr = nullptr;
			_oldValue = nullptr;
			_newValue = nullptr;
			_createUser = _odbc->Login;
			_createDate = DateTime::Now;
			_updateUser = nullptr;
			_updateDate = nullptr;


			String^ columns = "ID,ID_INTGR,EDIT_DATE,ID_ATTR,OLD_VAL,NEW_VAL,ID_POS,CREATE_USER,CREATE_DATE,UPDATE_USER,UPDATE_DATE,EDIT_TYPE,SYSTEM_N";
			_id = _odbc->GetLastFreeId(_odbc->schema + "INTEGRATION_EDITINGS");
			int idInteg = _result->Id;
			String^ editDate = _odbc->GetSqlDate(_editDate);
			String^ login = _odbc->GetSqlString(_createUser);
			String^ createDate = _odbc->GetSqlDate(_createDate);
			String^ sIdPos = _odbc->GetSqlString(_idPos->ToString());

			String^ squery = String::Format("insert into {0}INTEGRATION_EDITINGS ({1}) values ({2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13},{14})",
				_odbc->schema, columns, _id, idInteg, editDate, "NULL", "NULL", "NULL", sIdPos, login, createDate, "NULL", "NULL", _type, _nSystem);
			_odbc->ExecuteNonQuery(squery);
		}

		void WriteEditingPos()
		{
			_editDate = DateTime::Now;
			_createUser = _odbc->Login;
			_createDate = DateTime::Now;
			_updateUser = nullptr;
			_updateDate = nullptr;


			String^ columns = "ID,ID_INTGR,EDIT_DATE,ID_ATTR,OLD_VAL,NEW_VAL,ID_POS,CREATE_USER,CREATE_DATE,UPDATE_USER,UPDATE_DATE,EDIT_TYPE,SYSTEM_N";
			_id = _odbc->GetLastFreeId(_odbc->schema + "INTEGRATION_EDITINGS");
			int idInteg = _result->Id;
			String^ editDate = _odbc->GetSqlDate(_editDate);
			String^ login = _odbc->GetSqlString(_createUser);
			String^ createDate = _odbc->GetSqlDate(_createDate);
			String^ oldVal = _odbc->GetSqlString(_oldValue->ToString());
			String^ newVal = _odbc->GetSqlString(_newValue->ToString());
			String^ sIdPos = _odbc->GetSqlString(_idPos->ToString());

			String^ squery = String::Format("insert into {0}INTEGRATION_EDITINGS ({1}) values ({2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13},{14})",
				_odbc->schema, columns, _id, idInteg, editDate, _attr->Id, oldVal, newVal, sIdPos, login, createDate, "NULL", "NULL", _type, _nSystem);
			_odbc->ExecuteNonQuery(squery);
		}



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Editting() 
		{

		}


	};
}