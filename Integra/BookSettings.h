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
		property bool HasGroup
		{
			bool get()
			{
				if (_groupId == 0)
				{
					return false;
				}
				return true;
			}
		}
		property int Id
		{
			int get()
			{
				return _id;
			}
		}
		property OdbcClass^ Odbc
		{
			OdbcClass^ get()
			{
				if (_workOdbc == nullptr)
				{
					if (_driver == nullptr)
					{
						_workOdbc = gcnew OdbcClass(_login, _password, _tnsDatabase);
					}
					else
					{
						_workOdbc = gcnew OdbcClass(_driver);
					}
				}
				return _workOdbc;
			}
		}
		property String^ AttrIdFullcode
		{
			String^ get()
			{
				if (_attrIdFullcode == nullptr)
				{
					SetAttrIdName();
				}
				return _attrIdFullcode;
			}

		}

		property String^ AttrTitleFullcode
		{
			String^ get()
			{
				if (_attrTitleFullcode == nullptr)
				{
					SetAttrTitleName();
				}
				return _attrTitleFullcode;
			}

		}

	private:
		OdbcClass^ _odbc;
		OdbcClass^ _workOdbc;
		int _id;

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
		int _groupId;

		int _attrIdId;
		String^ _attrIdFullcode;
		int _attrTitleId;
		String^ _attrTitleFullcode;
		

	public:
		BookSettings(int parametrsId, OdbcClass^ odbc)
		{
			_odbc = odbc;
			_id = parametrsId;
			Set(parametrsId);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BookSettings() 
		{

		}

	public:
		List<Attribute^>^ GetUseAttrs()
		{
			String^ squery = String::Format("select ID, FULL_CODE, NAME, SCHEMA_NAME, TABLE_NAME, ATTR_NAME from {0}INTEGRATION_ATTRIBUTES" + 
				" where ID_INTGR_BOOK = {1}", _odbc->schema, _id);
			List<Object^>^ oList = _odbc->ExecuteQuery(squery);
			List<Attribute^>^ list = gcnew List<Attribute ^>();
			for (int i = 0; i < oList->Count; i+=6)
			{
				int id = OdbcClass::GetInt(oList[i]);
				String^ fullTable = OdbcClass::GetResString(oList[i+1]);
				String^ name = OdbcClass::GetResString(oList[i+2]);
				String^ schemaName = OdbcClass::GetResString(oList[i+3]);
				String^ tableName = OdbcClass::GetResString(oList[i+4]);
				String^ attrName = OdbcClass::GetResString(oList[i+5]);
				Attribute^ attr = gcnew Attribute(schemaName, tableName, attrName, name, id);
				list->Add(attr);
			}
			return list;
		}

	private:
		Void Set(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select ID_SYSTEM, ID_BOOK, LOGIN, PASSWORD, TNS_DATABASE, HOST, PORT, SERVICE_NAME, SID, DRIVER, IS_SEMANTIC, GROUP_ID, ATTR_ID, ATTR_TITLE from " + _odbc->schema + "INTEGRATION_BOOK where ID = " + id);
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
			_groupId = OdbcClass::GetInt(parametrs[11]);
			_attrIdId = OdbcClass::GetInt(parametrs[12]);
			_attrTitleId = OdbcClass::GetInt(parametrs[13]);
		}

		Void SetSystem(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select NAME from " + _odbc->schema + "INTEGRATED_SYSTEMS where ID = " + id);
			_systemName = parametrs[0]->ToString();
		}

		Void SetBook(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select NAME from " + _odbc->schema + "BOOKS where ID = " + id);
			_bookName = parametrs[0]->ToString();
		}

		void SetAttrIdName()
		{
			String^ squery = String::Format("select IA.FULL_CODE, IA.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IA, {0}INTEGRATION_BOOK IB " +
				"where IB.ATTR_ID = IA.ID and IB.ID = {1}", _odbc->schema, _id);
			List<Object^>^ list = _odbc->ExecuteQuery(squery);
			_attrIdFullcode = String::Format("{0}.{1}", list[0], list[1]);
		}

		void SetAttrTitleName()
		{
			String^ squery = String::Format("select IA.FULL_CODE, IA.ATTR_NAME from {0}INTEGRATION_ATTRIBUTES IA, {0}INTEGRATION_BOOK IB " +
				"where IB.ATTR_TITLE = IA.ID and IB.ID = {1}", _odbc->schema, _id);
			List<Object^>^ list = _odbc->ExecuteQuery(squery);
			_attrTitleFullcode = String::Format("{0}.{1}", list[0], list[1]);
		}

		Void SetLogPass(String^ login, String^ password)
		{
			_login = login;
			_password = password;
		}
	};
}