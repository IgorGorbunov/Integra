#pragma once

#include "ODBCclass.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// ����� 
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
				if (DataType == "������")
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
			//todo
			String^ get()
			{
				return _dataType;
			}
			void set(String^ value)
			{
				value = value->ToUpper();
				if(value == "������" || value == "VARCHAR2" || value == "�����" || value == "STRING" || value == "VARCHAR"  || value == "CHAR" || value == "SYSTEM.STRING")
				{
					_dataType = "������";
				}
				//release
				if(value == "����� �����" || value == "INTEGER" || value == "NUMBER")
				{
					_dataType = "����� �����";
				}
				if(value == "����" || value == "DATE" || value == "DATETIME" || value == "SYSTEM.DATETIME")
				{
					_dataType = "����";
				}
				if(value == "����� � ��������� ������"  || value == "DECIMAL"  || value == "SYSTEM.DECIMAL")
				{
					_dataType = "����� � ��������� ������";
				}
				if(value == "����������"  || value == "BOOL"  || value == "BOOLEAN")
				{
					_dataType = "����������";
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

		property String^ GroupAttrCodeValue
		{
			String^ get()
			{
				return _groupAttrCodeValue;
			}
			void set(String^ val)
			{
				_groupAttrCodeValue = val;
			}
		}
		property String^ GroupAttrNameValue
		{
			String^ get()
			{
				return _groupAttrNameValue;
			}
			void set(String^ val)
			{
				_groupAttrNameValue = val;
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

		int _doubleLength;

		String^ _groupAttrCodeValue;
		String^ _groupAttrNameValue;

	public:

		virtual bool Equals(Object^ obj) override 
		 {
			 if (obj == nullptr || GetType() != obj->GetType()) 
				 return false;

			 Attribute^ attr2 = (Attribute^)obj;
			 return attr2->FullCode == FullCode;
		}

		virtual int GetHashCode() override
		{
			return FullCode->GetHashCode();
		}

		static bool operator ==(Attribute^ attr1, Attribute^ attr2) 
		{
			// If both are null, or both are same instance, return true.
			if (System::Object::ReferenceEquals(attr1, attr2))
			{
				return true;
			}

			// If one is null, but not both, return false.
			if (((Object^)attr1 == nullptr) || ((Object^)attr2 == nullptr))
			{
				return false;
			}

			return attr1->Equals(attr2);
		}

		static bool operator !=(Attribute^ attr1, Attribute^ attr2) 
		{
			return !(attr1==attr2);
		}

		virtual String^ ToString() override
		{
			return String::Format("({0}, {1}, {2}, {3})", _id, FullCode, Name, DataType);
		} 

		static List<Attribute^>^ GetAttributes(OdbcClass^ odbc, int idIntgrBook)
		{
			List<Attribute^>^ list;
			String^ squery = "select IAA.ID,IAA.NAME,IAA.SCHEMA_NAME,IAA.TABLE_NAME,IAA.ATTR_NAME,IAA.ID_INTGR_BOOK,IAA.DATA_TYPE,IAA.MAX_LENGTH from " +
				"{0}INTEGRATION_ATTRIBUTES IAA where IAA.ID_INTGR_BOOK = {1}";
			squery = String::Format(squery, odbc->schema, idIntgrBook);

			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				list = gcnew List<Attribute ^>();
				for (int i = 0; i < resList->Count; i+=8)
				{
					int attrId = OdbcClass::GetResInt(resList[i+0]);
					String^ attrName = resList[i+1]->ToString();
					String^ attrSchemaName = resList[i+2]->ToString();
					String^ attrTableName = resList[i+3]->ToString();
					String^ attrCode = resList[i+4]->ToString();
					int attrIntBookId = OdbcClass::GetResInt(resList[i+5]);
					String^ attrDataType = resList[i+6]->ToString();
					int attrMaxLength = OdbcClass::GetResInt(resList[i+7]);
					Attribute^ attr = gcnew Attribute(attrId, attrName, attrSchemaName, attrTableName, attrCode, attrIntBookId, attrDataType, attrMaxLength + "", odbc);
					list->Add(attr);
				}
			}

			return list;
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

		Attribute(int id, String^ name, String^ schemaName, String^ tableName, String^ attrCode, int integrationBookId, String^ dataType, String^ maxLength, int maxDoubleLength, OdbcClass^ odbc)
		{
			_id = id;
			_name = name;
			_schemaName = schemaName;
			_tableName = tableName;
			_attrName = attrCode;
			_idIntgrBook = integrationBookId;
			_dataType = dataType;
			MaxLength = maxLength;
			_doubleLength = maxDoubleLength;
			_odbc = odbc;
		}

		Attribute(String^ schema, String^ table, String^ code, String^ name)
		{
			Init(schema, table, code, name);
		}

		Attribute(String^ schema, String^ table, String^ code, String^ name, bool isNull)
		{
			Init(schema, table, code, name);
			CanBeNull = isNull;
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

		void SetDataType(String^ dataType, int maxLength, int doubleLength)
		{
			dataType = dataType->ToUpper();
			if(dataType == "������" || dataType == "VARCHAR2" || dataType == "�����" || dataType == "STRING" || dataType == "VARCHAR"  || dataType == "CHAR" || dataType == "SYSTEM.STRING")
			{
				_dataType = "������";
				MaxLength = maxLength + "";
				return;
			}
			if(dataType == "����� �����" || dataType == "INTEGER" || dataType == "SYSTEM.INT32")
			{
				_dataType = "����� �����";
				if (maxLength == 0)
				{
					MaxLength = "9";
				}
				else
				{
					MaxLength = maxLength + "";
				}
				return;
			}
			if(dataType == "����" || dataType == "DATE" || dataType == "DATETIME" || dataType == "SYSTEM.DATETIME")
			{
				_dataType = "����";
				if (maxLength == 0)
				{
					MaxLength = "7";
				}
				else
				{
					MaxLength = maxLength + "";
				}
				return;
			}
			if(dataType == "����� � ��������� ������"  || dataType == "DECIMAL"  || dataType == "SYSTEM.DECIMAL")
			{
				_dataType = "����� � ��������� ������";
				if (maxLength == 0)
				{
					MaxLength = "9";
					_doubleLength = 3;
				}
				else
				{
					MaxLength = maxLength + "";
					_doubleLength = doubleLength;
				}
				return;
			}
			if(dataType == "����������"  || dataType == "BOOL"  || dataType == "BOOLEAN")
			{
				_dataType = "����������";
				MaxLength = "";
				return;
			}


			if(dataType == "NUMBER")
			{
				if (doubleLength > 0)
				{
					_dataType = "����� � ��������� ������";
					MaxLength = maxLength + "";
					_doubleLength = doubleLength;
				}
				else
				{
					_dataType = "����� �����";
				}
				return;
			}
		}

		Object^ GetValue(String^ condition, bool isDb, OdbcClass^ odbc)
		{
			//todo
			if (isDb)
			{
				String^ query;
				if (String::IsNullOrEmpty(Schema))
				{
					query = String::Format("select ATABLE.{0} from {1}{2} ATABLE {3}", Code, Schema, Table, condition);
				}
				else
				{
					query = String::Format("select ATABLE.{0} from {1}.{2} ATABLE {3}", Code, Schema, Table, condition);
				}

				List<Object^>^ qlist = odbc->ExecuteQuery(query);
				if (qlist != nullptr && qlist->Count > 0)
				{
					return qlist[0];
				}
				return nullptr;
			}
			else
			{
				//todo
				return nullptr;
			}
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
			_idIntgrBook = OdbcClass::GetResInt(parametrs[5]);
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