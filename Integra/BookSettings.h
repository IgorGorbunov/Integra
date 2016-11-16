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
	public ref class BookSettings 
	{
	public:
		property String^ SystemName
		{
			String^ get()
			{
				return _systemName;
			}
		}
		property String^ BookName
		{
			String^ get()
			{
				return _bookName;
			}
		}
		property bool IsSemantic
		{
			bool get()
			{
				return _isSemantic;
			}
		}
		property String^ Login
		{
			String^ get()
			{
				return _login;
			}
		}
		property String^ Password
		{
			String^ get()
			{
				return _password;
			}
		}

	private:
		OdbcClass^ _odbc;

		String^ _systemName;
		String^ _bookName;

		String^ _login;
		String^ _password;

		String^ _tnsDatabase;
		String^ _host;
		String^ _port;
		String^ _serviceName;
		String^ _sid;
		String^ _driver;
		bool _isSemantic;

	public:
		BookSettings(int parametrsId, OdbcClass^ odbc)
		{
			_odbc = odbc;
			Set(parametrsId);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BookSettings() 
		{

		}

	private:
		Void Set(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select ID_SYSTEM, ID_BOOK, LOGIN, PASSWORD, TNS_DATABASE, HOST, PORT, SERVICE_NAME, SID, DRIVER, IS_SEMANTIC from " + OdbcClass::schema + "INTEGRATION_BOOK where ID = " + id);
			SetSystem(Decimal::ToInt32((Decimal)parametrs[0]));
			SetBook(Decimal::ToInt32((Decimal)parametrs[1]));
			SetLogPass(parametrs[2]->ToString(), parametrs[3]->ToString());
			_tnsDatabase = parametrs[4]->ToString();
			_host = parametrs[5]->ToString();
			_port = parametrs[6]->ToString();
			_serviceName = parametrs[7]->ToString();
			_sid = parametrs[8]->ToString();
			_driver = parametrs[9]->ToString();
			_isSemantic = (bool) Decimal::ToInt32((Decimal)parametrs[10]);

		}

		Void SetSystem(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select NAME from " + OdbcClass::schema + "INTEGRATED_SYSTEMS where ID = " + id);
			_systemName = parametrs[0]->ToString();
		}

		Void SetBook(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select NAME from " + OdbcClass::schema + "BOOKS where ID = " + id);
			_bookName = parametrs[0]->ToString();
		}

		Void SetLogPass(String^ login, String^ password)
		{
			_login = login;
			_password = password;
		}
	};
}