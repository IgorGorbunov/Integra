#pragma once

#include "ODBCclass.h"
#include "ComposeAttr.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class ComplexAttribute 
	{
	public:
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
		Attribute^ _recAttribute;
		ComposeAttribute^ _composeAttribute;
		String^ _name;
		//0 - композиция, 1 - выборка
		int _type;
		bool _writeSource;

		List<ComposeAttribute^>^ _composeAttributes;

		Attribute^ _selectAttribute;
		int _selectType;
		int _iFirstSymbol;
		int _nCol;
		String^ _symbols;
		int _iSelectPart;


	public:

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, List<Object^>^ composeAttrs, bool writeSource)
		{
			_odbc = odbc;
			_name = name;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_composeAttributes = gcnew List<ComposeAttribute ^>();
			bool firstComposeAttr = true;
			for each (Object^ o in composeAttrs)
			{
				Attribute^ attr;
				try
				{
					attr = (Attribute^)o;
					if (firstComposeAttr)
					{
						AddFirstComposeAttr(attr);
					}
					else
					{
						AddNextComposeAttr(attr);
					}
				}
				catch (InvalidCastException^ e)
				{
					if (firstComposeAttr)
					{
						AddFirstComposeAttr((String^)o);
					}
					else
					{
						AddNextComposeAttr((String^)o);
					}
				}
				firstComposeAttr = false;
			}
		}

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, bool writeSource, Attribute^ selectAttribute, int iFirstSymbol, int nCol)
		{
			_odbc = odbc;
			_name = name;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_iFirstSymbol = iFirstSymbol;
			_nCol = nCol;
			_selectType = 0;
			_selectAttribute = selectAttribute;
		}

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, bool writeSource, Attribute^ selectAttribute, String^ splitSymbols, int selectPart)
		{
			_odbc = odbc;
			_name = name;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_symbols = splitSymbols;
			_iSelectPart = selectPart;
			_selectType = 1;
			_selectAttribute = selectAttribute;
		}

		void AddFirstComposeAttr(Attribute^ attribute)
		{
			_composeAttribute = gcnew ComposeAttribute(_odbc, attribute);
			_composeAttributes->Add(_composeAttribute);
		}

		void AddFirstComposeAttr(String^ value)
		{
			_composeAttribute = gcnew ComposeAttribute(_odbc, value);
			_composeAttributes->Add(_composeAttribute);
		}

		void AddNextComposeAttr(Attribute^ attribute)
		{
			ComposeAttribute^ composeAttribute = gcnew ComposeAttribute(_odbc, attribute);
			_composeAttributes[_composeAttributes->Count-1]->AddNextAttribute(composeAttribute);
			_composeAttributes->Add(composeAttribute);
		}

		void AddNextComposeAttr(String^ value)
		{
			ComposeAttribute^ composeAttribute = gcnew ComposeAttribute(_odbc, value);
			_composeAttributes[_composeAttributes->Count-1]->AddNextAttribute(composeAttribute);
			_composeAttributes->Add(composeAttribute);
		}


		void InsertToDb(int intgrShemaId)
		{
			for (int i = _composeAttributes->Count - 1; i >= 0; i--)
			{
				_composeAttributes[i]->InsertToDb();
			}

			String^ columns = "ID,NAME_ATTR,COMPLEX_TYPE,START_COMPOSE_ATTR_ID,SELECT_TYPE,FIRST_SYMBOL,SYMBOL_COUNT,SPLIT_SYMBOLS,USE_PART,CREATE_USER,CREATE_DATE";
			String^ sqlUser = OdbcClass::GetSqlString(_odbc->Login);
			String^ sqlDate = _odbc->GetSqlDate(DateTime::Now);

			_id = _odbc->GetLastFreeId(_odbc->schema + "COMPLEX_ATTRS");
			String^ sName = OdbcClass::GetSqlString(_name);
			String^ sComposeID;
			if (_composeAttributes != nullptr && _composeAttributes->Count > 0)
			{
				sComposeID = _composeAttributes[0]->Id + "";
			}
			else
			{
				sComposeID = "NULL";
			}
			String^ selectType;
			String^ firstSymbol;
			String^ symbolCount;
			String^ splitSymbols;
			String^ usePart;

			if (_type == 1)
			{
				selectType = _selectType + "";
				if (_selectType == 0)
				{
					firstSymbol = _iFirstSymbol + "";
					symbolCount = _nCol + "";
					splitSymbols = "NULL";
					usePart = "NULL";
				}
				else
				{
					firstSymbol = "NULL";
					symbolCount = "NULL";
					//todo bad symbols
					splitSymbols = OdbcClass::GetSqlString(_symbols);
					usePart = _iSelectPart + "";
				}
			}
			else
			{
				selectType = "NULL";
				firstSymbol = "NULL";
				symbolCount = "NULL";
				splitSymbols = "NULL";
				usePart = "NULL";
			}


			String^ sQuery = String::Format("insert into {0}COMPLEX_ATTRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12})",
				_odbc->schema, columns, _id, sName, _type, sComposeID, selectType, firstSymbol, symbolCount, splitSymbols, usePart, sqlUser, sqlDate);
			_odbc->ExecuteNonQuery(sQuery);

			if (_writeSource)
			{
				columns = "ID,ID_SOURCE_ATTRIBUTE,ID_PARAMETRS,CREATE_USER,CREATE_DATE,ID_TARGET_COMPLEX_ATTR";
				int idAttrPair = _odbc->GetLastFreeId(_odbc->schema + "ATTRIBUTE_PAIRS");

				sQuery = String::Format("insert into {0}ATTRIBUTE_PAIRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
					_odbc->schema, columns, idAttrPair, _recAttribute->Id, intgrShemaId, sqlUser, sqlDate, _id);
				_odbc->ExecuteNonQuery(sQuery);
			}
			else
			{
				columns = "ID,ID_TARGET_ATTRIBUTE,ID_PARAMETRS,CREATE_USER,CREATE_DATE,ID_SOURCE_COMPLEX_ATTR";
				int idAttrPair = _odbc->GetLastFreeId(_odbc->schema + "ATTRIBUTE_PAIRS");

				sQuery = String::Format("insert into {0}ATTRIBUTE_PAIRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7})",
					_odbc->schema, columns, idAttrPair, _recAttribute->Id, intgrShemaId, sqlUser, sqlDate, _id);
				_odbc->ExecuteNonQuery(sQuery);
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ComplexAttribute() 
		{

		}


	};
}