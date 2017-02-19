#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	///  Î‡ÒÒ 
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
		property bool IsString
		{
			bool get()
			{
				if (DataType == "—“–Œ ¿")
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
				if (String::IsNullOrEmpty(Schema))
				{
					return Table;
				}
				return String::Format("{0}.{1}", Schema, Table);
			}
		}
		property String^ FullCode
		{
			String^ get()
			{
				if (_fullCode == nullptr)
				{
					if (String::IsNullOrEmpty(_schemaName))
					{
						_fullCode = String::Format("{0}.{1}", _tableName, _attrName);
					}
					else
					{
						_fullCode = String::Format("{0}.{1}.{2}", _schemaName, _tableName, _attrName);
					}
				}
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
		property String^ DataType
		{
			String^ get()
			{
				return _dataType;
			}
			void set(String^ value)
			{
				value = value->ToUpper();
				if(value == "—“–Œ ¿" || value == "VARCHAR2" || value == "“≈ —“" || value == "STRING" || value == "VARCHAR"  || value == "CHAR" || value == "SYSTEM.STRING")
				{
					_dataType = "—“–Œ ¿";
				}
				//release
				if(value == "÷≈ÀŒ≈ ◊»—ÀŒ" || value == "INTEGER" || value == "NUMBER" || value == "SYSTEM.DECIMAL")
				{
					_dataType = "÷≈ÀŒ≈ ◊»—ÀŒ";
				}
				if(value == "ƒ¿“¿" || value == "DATE" || value == "DATETIME" || value == "SYSTEM.DATETIME")
				{
					_dataType = "ƒ¿“¿";
				}
				if(value == "◊»—ÀŒ — œÀ¿¬¿ﬁŸ≈… “Œ◊ Œ…"  || value == "DECIMAL"  || value == "SYSTEM.DECIMAL")
				{
					_dataType = "◊»—ÀŒ — œÀ¿¬¿ﬁŸ≈… “Œ◊ Œ…";
				}
			}
		}
		property int Id
		{
			int get()
			{
				return _id;
			}
			void set(int id)
			{
				_id = id;
			}
		}


		bool UseChecked;
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
		String^ _dataType;
		int _idIntgrBook;


	public:

		static void WriteAttribute()
		{

		}

		void Init(String^ schema, String^ table, String^ code, String^ name)
		{
			_schemaName = schema;
			_tableName = table;
			_attrName = code;
			_name = name;
			if (String::IsNullOrEmpty(_schemaName))
			{
				_fullCode = String::Format("{0}.{1}", _tableName, _attrName);
			}
			else
			{
				_fullCode = String::Format("{0}.{1}.{2}", _schemaName, _tableName, _attrName);
			}
		}

		Attribute(int id, OdbcClass^ odbc)
		{
			_id = id;
			_odbc = odbc;
			Set(_id);
		}

		Attribute(int id, String^ name, String^ schemaName, String^ tableName, String^ attrCode, int integrationBookId, String^ dataType, String^ maxLength, OdbcClass^ odbc)
		{
			_id = id;
			_name = name;
			_schemaName = schemaName;
			_tableName = tableName;
			_attrName = attrCode;
			_idIntgrBook = integrationBookId;
			_dataType = dataType;
			MaxLength = maxLength;
			_odbc = odbc;
		}

		Attribute(String^ schema, String^ table, String^ code, String^ name)
		{
			Init(schema, table, code, name);
		}

		Attribute(String^ fullTable, String^ code, String^ name)
		{
			String^ schema = "";
			String^ table;
			array<String^>^ arr = fullTable->Trim()->Split('.');
			List<String^>^ list = gcnew List<String ^>(arr);
			for (int i = 0; i < list->Count; i++)
			{
				if (list[i] == nullptr || list[i] == "")
				{
					list->RemoveAt(i);
					i--;
				}
			}

			if (list->Count > 1)
			{
				if	(list->Count > 2)
				{
					schema = "";
					table = fullTable;
				}
				else
				{
					schema = list[0];
					table = list[1];
				}
				
			}
			else
			{
				schema = "";
				table = arr[0];
			}
			Init(schema, table, code, name);
		}

		Attribute(String^ schema, String^ table, String^ code, String^ name, int id)
		{
			Init(schema, table, code, name);
			_id = id;
		}

		Object^ GetValue(String^ condition, bool isDb)
		{
			//todo
			if (isDb)
			{
				String^ query = String::Format("select {0}ATABLE.{1} from {0}{2} ATABLE {3}", _odbc->schema, Code, Table, condition);
				List<Object^>^ qlist = _odbc->ExecuteQuery(query);
				return qlist[0];
			}
			else
			{
				//todo
				return nullptr;
			}
		}

	protected:
		/// <summary>
		/// ŒÒ‚Ó·Ó‰ËÚ¸ ‚ÒÂ ËÒÔÓÎ¸ÁÛÂÏ˚Â ÂÒÛÒ˚.
		/// </summary>
		~Attribute() 
		{

		}

	private:
		Void Set(int id)
		{
			List<Object^>^ parametrs = _odbc->ExecuteQuery("select FULL_CODE, NAME, SCHEMA_NAME, TABLE_NAME, ATTR_NAME, ID_INTGR_BOOK, DATA_TYPE, MAX_LENGTH from " + _odbc->schema + "INTEGRATION_ATTRIBUTES where ID = " + id);
			_name = parametrs[1]->ToString();
			_schemaName = parametrs[2]->ToString();
			_tableName = parametrs[3]->ToString();
			_attrName = parametrs[4]->ToString();
			_idIntgrBook = Decimal::ToInt32((Decimal)parametrs[5]);
			_dataType = parametrs[6]->ToString();
			MaxLength = parametrs[7]->ToString();
			if (String::IsNullOrEmpty(_schemaName))
			{
				_fullCode = String::Format("{0}.{1}", _tableName, _attrName);
			}
			else
			{
				_fullCode = String::Format("{0}.{1}.{2}", _schemaName, _tableName, _attrName);
			}
		}

	};
}