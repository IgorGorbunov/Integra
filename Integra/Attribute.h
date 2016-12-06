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
				return Schema + "." + Table;
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
		property int Id
		{
			int get()
			{
				return _id;
			}

		}

		bool UseChecked;
		String^ DataType;
		String^ MaxLength;
		bool CanBeNull;


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
		void Init(String^ schema, String^ table, String^ code, String^ name)
		{
			_schemaName = schema;
			_tableName = table;
			_attrName = code;
			_name = name;
			_fullCode = String::Format("{0}.{1}.{2}", _schemaName, _tableName, _attrName);
		}

		Attribute(int id, OdbcClass^ odbc)
		{
			_id = id;
			_odbc = odbc;
			Set(_id);
		}

		Attribute(String^ schema, String^ table, String^ code, String^ name)
		{
			Init(schema, table, code, name);
		}

		Attribute(String^ schema, String^ table, String^ code, String^ name, int id)
		{
			Init(schema, table, code, name);
			_id = id;
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

		Void ParseFullCode()
		{


		}
	};
}