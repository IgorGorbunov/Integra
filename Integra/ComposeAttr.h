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
	public ref class ComposeAttribute 
	{
	public:
		property ComposeAttribute^ NextAttribute
		{
			ComposeAttribute^ get()
			{
				if (_nextAttribute == nullptr)
				{
					return nullptr;
				}
				else
				{
					return _nextAttribute;
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
		property Attribute^ Attribut
		{
			Attribute^ get()
			{
				return _attribute;
			}
		}
		property bool HasStringValue
		{
			bool get()
			{
				if (_type == 1)
				{
					return true;
				}
				return false;
			}
		}
		property String^ StringValue
		{
			String^ get()
			{
				return _stringValue;
			}
		}

	private:
		OdbcClass^ _odbc;

		int _id;
		String^ _stringValue;
		Attribute^ _attribute;
		ComposeAttribute^ _nextAttribute;
		// 0 - attr, 1 - string value
		int _type;


	public:

		static void Delete(OdbcClass^ odbc, int id)
		{
			String^ squery = String::Format("select CAA.NEXT_ID from {0}COMPOSE_ATTRS CAA where CAA.ID = {1}", odbc->schema, id);
			List<Object^>^ resList = odbc->ExecuteQuery(squery);
			if (resList != nullptr && resList->Count > 0)
			{
				int cId = OdbcClass::GetResInt(resList[0]);
				Delete(odbc, cId);
			}
			squery = String::Format("delete from {0}COMPOSE_ATTRS IBB where IBB.ID = {1}", odbc->schema, id);
			odbc->ExecuteNonQuery(squery);
		}

		ComposeAttribute(OdbcClass^ odbc, String^ value)
		{
			_odbc = odbc;
			_stringValue = value;
			_type = 1;
		}

		ComposeAttribute(OdbcClass^ odbc, Attribute^ attribute)
		{
			_odbc = odbc;
			_attribute = attribute;
			_type = 0;
		}

		ComposeAttribute(OdbcClass^ odbc, int id)
		{
			_odbc = odbc;
			_type = 1;
			_id = id;
			String^ squery = "select IAA.ID, IAA.NAME, IAA.SCHEMA_NAME, IAA.TABLE_NAME, IAA.ATTR_NAME, IAA.ID_INTGR_BOOK, IAA.DATA_TYPE, IAA.MAX_LENGTH, CAA.NEXT_ID, CAA.COMPOSE_VAL from {0}COMPOSE_ATTRS CAA, {0}INTEGRATION_ATTRIBUTES IAA where CAA.ID = {1} and CAA.ATTR_ID = IAA.ID";
			squery = String::Format(squery, _odbc->schema, id);

			List<Object^>^ resList = _odbc->ExecuteQuery(squery);
			for (int i = 0; i < resList->Count; i+=10)
			{
				int attrId = _odbc->GetResInt(resList[i]);
				if (attrId != -1)
				{
					_type = 0;
					String^ attrName = _odbc->GetResString(resList[i+1]);
					String^ schemaName = _odbc->GetResString(resList[i+2]);
					String^ tableName = _odbc->GetResString(resList[i+3]);
					String^ attrCode = _odbc->GetResString(resList[i+4]);
					int idIntgrBook = _odbc->GetResInt(resList[i+5]);
					String^ attrDataType = _odbc->GetResString(resList[i+6]);
					String^ attrMaxLength = _odbc->GetResString(resList[i+7]);
					_attribute = gcnew Attribute(attrId, attrName, schemaName, tableName, attrCode, idIntgrBook, attrDataType, attrMaxLength, _odbc);
				}

				int nextId = _odbc->GetResInt(resList[i+8]);
				_stringValue = _odbc->GetResString(resList[i+9]);
				if (nextId != -1)
				{
					_nextAttribute = gcnew ComposeAttribute(_odbc, nextId);
				}
			}
		}

		void AddNextAttribute(ComposeAttribute^ attribute)
		{
			_nextAttribute = attribute;
		}


		void InsertToDb()
		{
			String^ columns = "ID,ATTR_ID,NEXT_ID,COMPOSE_VAL,CREATE_USER,CREATE_DATE";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			String^ sVal = OdbcClass::GetSqlString(_stringValue);
			_id = _odbc->GetLastFreeId(_odbc->schema + "COMPOSE_ATTRS");
			String^ nextId;
			if (_nextAttribute == nullptr)
			{
				nextId = "-1";
			}
			else
			{
				nextId = _nextAttribute->_id + "";
			}
			String^ sAttrId;
			if (_attribute == nullptr)
			{
				sAttrId = "NULL";
			}
			else
			{
				sAttrId = _attribute->Id + "";
			}


			String^ sQuery = String::Format("insert into {0}COMPOSE_ATTRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
				_odbc->schema, columns, _id, sAttrId, nextId, sVal, sqlUser, sqlDate);
			_odbc->ExecuteNonQuery(sQuery);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ComposeAttribute() 
		{

		}


	};
}