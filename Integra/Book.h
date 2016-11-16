#pragma once

#include "Logger.h"
#include "BookSettings.h"


namespace Integra {

	using namespace System::Collections::Generic;

	/// <summary>
	/// Класс spravochnika Semantic
	/// </summary>
	public ref class Book
	{

	protected:
		BookSettings^ _bookSettings;
		IntegrationSettings^ _intSettings;

	public:
		Book(BookSettings^ bookSettings, IntegrationSettings^ intSettings) 
		{
			_bookSettings = bookSettings;
			_intSettings = intSettings;
		}



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Book() 
		{

		}


	public:
		virtual List<Position^>^ GetAllPositions() abstract;
		virtual List<Position^>^ GetAllPositions2(System::ComponentModel::BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs ^ e) abstract;
		virtual List<Position^>^ GetAllPositions22(int% n) abstract;

	protected:

		List<Object^>^ GetSourceTitle()
		{
			return OdbcClass::Odbc->ExecuteQuery("select distinct FULL_CODE from " + OdbcClass::schema + "INTEGRATION_ATTRIBUTES where ID in (select ID_SOURCE_ATTRIBUTE from " + OdbcClass::schema + "ATTRIBUTE_PAIRS where ID_PARAMETRS = " + _intSettings->Id + ")");
		}

		List<Object^>^ GetTargetTitle()
		{
			return OdbcClass::Odbc->ExecuteQuery("select distinct FULL_CODE from " + OdbcClass::schema + "INTEGRATION_ATTRIBUTES where ID in (select ID_TARGET_ATTRIBUTE from " + OdbcClass::schema + "ATTRIBUTE_PAIRS where ID_PARAMETRS = " + _intSettings->Id + ")");
		}
	};
}