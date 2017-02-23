#pragma once

#include "ODBCclass.h"
#include "IntegrationSettings.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class IntegrationResult 
	{
	public:
		property int Id
		{
			int get()
			{
				return _id;
			}
		}

	private:
		OdbcClass^ _odbc;

		int _id;
		int _idInteg;
		IntegrationSettings^ _settings;
		// 0 - auto, 1 - manual exact, 2 - manual rough
		int _type;

		DateTime^ _startTime;
		String^ _login;
		String^ _state;

		String^ _createUser;
		DateTime^ _createDate;
		String^ _updateUser;
		DateTime^ _updateTime;

	public:

		static List<IntegrationResult^>^ GetAllIntegResults(OdbcClass^ odbc)
		{
			List<IntegrationResult^>^ list = gcnew List<IntegrationResult ^>();
			String^ columns = "ID,ID_INTGR,STATE,INTEG_USER,INTEG_DATE,CREATE_USER,CREATE_DATE,UPDATE_USER,UPDATE_DATE";
			String^ squery = String::Format("select {1} from {0}INTEGRATION_RESULTS", odbc->schema, columns);
			List<Object^>^ queryList = odbc->ExecuteQuery(squery);
			for (int i = 0; i < queryList->Count; i+=9)
			{
				int id = OdbcClass::GetResInt(queryList[i+0]);
				int idInteg = OdbcClass::GetResInt(queryList[i+1]);
				String^ state = OdbcClass::GetResString(queryList[i+2]);
				String^ integUser = OdbcClass::GetResString(queryList[i+3]);
				DateTime^ integDate = OdbcClass::GetResDate(queryList[i+4]);
				String^ createUser = OdbcClass::GetResString(queryList[i+5]);
				DateTime^ createDate = OdbcClass::GetResDate(queryList[i+6]);
				String^ updateUser = OdbcClass::GetResString(queryList[i+7]);
				DateTime^ updateDate = OdbcClass::GetResDate(queryList[i+8]);

				IntegrationResult^ intResult = gcnew IntegrationResult(odbc, id, idInteg, state, integUser, integDate, createUser, createDate, updateUser, updateDate);
				list->Add(intResult);
			}
			return list;
		}

		IntegrationResult(OdbcClass^ odbc, IntegrationSettings^ settings, int type)
		{
			_odbc = odbc;
			_settings = settings;
			_type = type;
		}

		IntegrationResult(OdbcClass^ odbc, int id, int idInteg, String^ state, String^ userLogin, DateTime^ integDate, 
			String^ createUser, DateTime^ createDate, String^ updateUser, DateTime^ updateTime)
		{
			_odbc = odbc;
			_id = id;
			_idInteg = idInteg;
			_state = state;
			_login = userLogin;
			_startTime = integDate;

			_createUser = createUser;
			_createDate = createDate;
			_updateUser = updateUser;
			_updateTime = updateTime;
		}

		void WriteDbStart()
		{
			_state = "Не окончено";
			_login = _odbc->Login;
			_startTime = DateTime::Now;

			String^ columns = "ID,ID_INTGR,STATE,INTEG_USER,INTEG_DATE,CREATE_USER,CREATE_DATE,UPDATE_USER,UPDATE_DATE,INT_TYPE";
			_id = _odbc->GetLastFreeId(_odbc->schema + "INTEGRATION_RESULTS");
			_idInteg = _settings->Id;
			String^ state = OdbcClass::GetSqlString(_state);
			String^ startTime = _odbc->GetSqlDate(_startTime);
			String^ login = _odbc->GetSqlString(_login);

			String^ squery = String::Format("insert into {0}INTEGRATION_RESULTS ({1}) values ({2},{3},{4},{5},{6},{7},{8},{9},{10},{11})",
				_odbc->schema, columns, _id, _idInteg, state, login, startTime, login, startTime, "NULL", "NULL", _type);
			_odbc->ExecuteNonQuery(squery);
		}

		void StopIntegration()
		{
			_state = "Окончено успешно";
			String^ squery = String::Format("update {0}INTEGRATION_RESULTS set STATE = {1} where ID = {2}", _odbc->schema, _odbc->GetSqlString(_state), _id);
			_odbc->ExecuteNonQuery(squery);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~IntegrationResult() 
		{

		}


	};
}