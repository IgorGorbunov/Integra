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
	public ref class AutoIntegration 
	{
	public:
		property int Id
		{
			int get()
			{
				return _id;
			}
		}
		property int SchemaId
		{
			int get()
			{
				return _schemaId;
			}
		}
		property bool IsOn
		{
			bool get()
			{
				return _isOn;
			}
		}
		property DateTime^ StartTime
		{
			DateTime^ get()
			{
				return _startTime;
			}
		}
		property DateTime^ LastStart
		{
			DateTime^ get()
			{
				return _lastStart;
			}
		}
		property int StartPeriod
		{
			int get()
			{
				return _startPerion;
			}
		}

	private:
		OdbcClass^ _odbc;

		int _id;
		int _schemaId;
		DateTime^ _startTime;
		bool _isOn;
		// 0 - everyDay, 1 - everyWeek, 2 - everyMonth, 3 - everyQuarter, 4 - everyYear
		int _startPerion;
		String^ _name;
		DateTime^ _lastStart;

	public:

		static List<AutoIntegration^>^ GetAllAutoIntegrations(OdbcClass^ odbc)
		{
			String^ squery = "select AISS.ID, AISS.INT_SCHEMA_ID, AISS.START_TIME, AISS.ON_OFF, AISS.START_PERIOD, AISS.INT_NAME, AISS.LAST_START " +
				"from {0}AUTO_INT_CONFIGS AISS ";
			squery = String::Format(squery, odbc->schema);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			List<AutoIntegration^>^ autoIntegrations;
			if (resList != nullptr && resList->Count > 0)
			{
				autoIntegrations = gcnew List<AutoIntegration ^>();
			}

			for (int i = 0; i < resList->Count; i+=7)
			{
				int id = odbc->GetResInt(resList[i+0]);
				int schemaId = odbc->GetResInt(resList[i+1]);
				DateTime^ startTime = odbc->GetResDate(resList[i+2]);
				int iOnOff = odbc->GetResInt(resList[i+3]);
				bool isOn;
				if (iOnOff == 1)
				{
					isOn = true;
				}
				else
				{
					isOn = false;
				}
				int startPeriod = odbc->GetResInt(resList[i+4]);
				String^ name = odbc->GetResString(resList[i+5]);
				DateTime^ lastStart = odbc->GetResDate(resList[i+6]);

				AutoIntegration^ autoIntegration = gcnew AutoIntegration(odbc, id, schemaId, startTime, isOn, startPeriod, name, lastStart);
				autoIntegrations->Add(autoIntegration);
			}
			return autoIntegrations;
		}

		AutoIntegration(OdbcClass^ odbc, int id, int schemaId, DateTime^ startTime, bool isOn, int startPeriod, String^ name, DateTime^ lastStart)
		{
			_odbc = odbc;
			_id	= id;
			_schemaId = schemaId;
			_startTime = startTime;
			_isOn = isOn;
			_startPerion = startPeriod;
			_name = name;
			_lastStart = lastStart;
		}

		void UpdateDbNewStart()
		{
			String^ sUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sDate = _odbc->GetSqlDate(DateTime::Now);
			String^ squery = String::Format("update {0}AUTO_INT_CONFIGS set LAST_START = {1}, UPDATE_USER = {2}, UPDATE_DATE = {1} where ID = {3}", 
				_odbc->schema, sDate, sUser, Id);
			_odbc->ExecuteNonQuery(squery);
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AutoIntegration() 
		{

		}


	};
}