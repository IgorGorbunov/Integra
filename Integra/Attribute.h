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
	public ref class Attribute 
	{
	public:
		property bool IsService
		{
			bool get()
			{
				if (_attrName[0] == '^')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		property String^ Code
		{
			String^ get()
			{
				return _attrName;
			}
		}
		property String^ FullTable
		{
			String^ get()
			{
				return _schemaName + "." + _tableName;
			}
		}
		property String^ FullCode
		{
			String^ get()
			{
				return _fullCode;
			}
		}
		property String^ Schema
		{
			String^ get()
			{
				return _schemaName;
			}
		}
		property String^ Table
		{
			String^ get()
			{
				return _tableName;
			}
		}
		property String^ Name
		{
			String^ get()
			{
				return _name;
			}
		}



	private:
		OdbcClass^ _odbc;

		int _id;
		String^ _fullCode;
		String^ _name;
		String^ _schemaName;
		String^ _tableName;
		String^ _attrName;
		int _idIntgrBook;

	public:
		Attribute(int id, OdbcClass^ odbc)
		{
			_id = id;
			_odbc = odbc;
			Set(_id);
		}
		Attribute(String^ fullCodeAttr, String^ name)
		{
			array<String^>^ arr = fullCodeAttr->Split('.');
			_attrName = arr[arr->Length-1];
			_fullCode = "";
			for (int i = 0;i < arr->Length - 1; i++)
			{
				if (String::IsNullOrEmpty(arr[i]))
					continue;
				_fullCode += String::Format("{0}.", arr[i]);
			}
			_name = name;
			_tableName = _fullCode;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Attribute() 
		{

		}

	private:
		Void Set(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select FULL_CODE, NAME, SCHEMA_NAME, TABLE_NAME, ATTR_NAME, ID_INTGR_BOOK from " + _odbc->schema + ".INTEGRATION_ATTRIBUTES where ID = " + id);
			_fullCode = parametrs[0]->ToString();
			_name = parametrs[1]->ToString();
			_schemaName = parametrs[2]->ToString();
			_tableName = parametrs[3]->ToString();
			_attrName = parametrs[4]->ToString();
			_idIntgrBook = Decimal::ToInt32((Decimal)parametrs[5]);
		}


	};
}