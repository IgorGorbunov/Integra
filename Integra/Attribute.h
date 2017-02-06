#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Êëàññ 
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
				if(value == "ÑÒĞÎÊÀ" || value == "VARCHAR2" || value == "ÒÅÊÑÒ" || value == "STRING" || value == "VARCHAR"  || value == "CHAR" || value == "SYSTEM.STRING")
				{
					_dataType = "ÑÒĞÎÊÀ";
				}
				//release
				if(value == "ÖÅËÎÅ ×ÈÑËÎ" || value == "INTEGER" || value == "NUMBER" || value == "SYSTEM.DECIMAL")
				{
					_dataType = "ÖÅËÎÅ ×ÈÑËÎ";
				}
				if(value == "ÄÀÒÀ" || value == "DATE" || value == "DATETIME" || value == "SYSTEM.DATETIME")
				{
					_dataType = "ÄÀÒÀ";
				}
				if(value == "×ÈÑËÎ Ñ ÏËÀÂÀŞÙÅÉ ÒÎ×ÊÎÉ"  || value == "DECIMAL"  || value == "SYSTEM.DECIMAL")
				{
					_dataType = "×ÈÑËÎ Ñ ÏËÀÂÀŞÙÅÉ ÒÎ×ÊÎÉ";
				}
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
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
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