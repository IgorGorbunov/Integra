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

	private:
		OdbcClass^ _odbc;

		int _id;
		String^ _stringValue;
		Attribute^ _attribute;
		ComposeAttribute^ _nextAttribute;
		// 0 - attr, 1 - string value
		int _type;


	public:

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

		void AddNextAttribute(Attribute^ attribute)
		{
			_nextAttribute = gcnew ComposeAttribute(_odbc, attribute);
		}

		void AddNextAttribute(String^ value)
		{
			_nextAttribute = gcnew ComposeAttribute(_odbc, value);
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
				nextId = "NULL";
			}
			else
			{
				nextId = _nextAttribute->_id + "";
			}

			String^ sQuery = String::Format("insert into {0}COMPOSE_ATTRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
				_odbc->schema, columns, _id, _attribute->Id, nextId, sVal, sqlUser, sqlDate);
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