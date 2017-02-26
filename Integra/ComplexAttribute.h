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
		property Attribute^ SelectAttribute
		{
			Attribute^ get()
			{
				if (_type == 1)
				{
					if (_selectAttribute == nullptr)
					{
						_selectAttribute = gcnew Attribute(_selectAttributeId, _odbc);
					}
					return _selectAttribute;
				}
				return nullptr;
			}

		}

	private:
		OdbcClass^ _odbc;

		int _id;
		Attribute^ _recAttribute;
		ComposeAttribute^ _firstComposeAttribute;
		List<ComposeAttribute^>^ _composeAttributes;
		int _firstComposeAttrId;

		String^ _name;
		//0 - композиция, 1 - выборка
		int _type;
		bool _writeSource;

		

		Attribute^ _selectAttribute;
		int _selectAttributeId;

		int _selectType;
		int _iFirstSymbol;
		int _nCol;
		String^ _symbols;
		int _iSelectPart;


	public:

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, List<Object^>^ composeAttrs, bool writeSource)
		{
			_odbc = odbc;
			_type = 0;
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
				catch (InvalidCastException^)
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

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, bool writeSource, int firstComposeAttrId)
		{
			_odbc = odbc;
			_type = 0;
			_name = name;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_firstComposeAttrId = firstComposeAttrId;
		}

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, bool writeSource, Attribute^ selectAttribute, int iFirstSymbol, int nCol)
		{
			_odbc = odbc;
			_name = name;
			_type = 1;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_iFirstSymbol = iFirstSymbol;
			_nCol = nCol;
			_selectType = 0;
			_selectAttribute = selectAttribute;
		}

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, bool writeSource, int selectAttributeId, int iFirstSymbol, int nCol)
		{
			_odbc = odbc;
			_name = name;
			_type = 1;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_iFirstSymbol = iFirstSymbol;
			_nCol = nCol;
			_selectType = 0;
			_selectAttributeId = selectAttributeId;
		}

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, bool writeSource, Attribute^ selectAttribute, String^ splitSymbols, int selectPart)
		{
			_odbc = odbc;
			_name = name;
			_type = 1;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_symbols = splitSymbols;
			_iSelectPart = selectPart;
			_selectType = 1;
			_selectAttribute = selectAttribute;
		}

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name, bool writeSource, int selectAttributeId, String^ splitSymbols, int selectPart)
		{
			_odbc = odbc;
			_name = name;
			_type = 1;
			_recAttribute = recAttribute;
			_writeSource = writeSource;
			_symbols = splitSymbols;
			_iSelectPart = selectPart;
			_selectType = 1;
			_selectAttributeId = selectAttributeId;
		}

		void AddFirstComposeAttr(Attribute^ attribute)
		{
			_firstComposeAttribute = gcnew ComposeAttribute(_odbc, attribute);
			_composeAttributes->Add(_firstComposeAttribute);
		}

		void AddFirstComposeAttr(String^ value)
		{
			_firstComposeAttribute = gcnew ComposeAttribute(_odbc, value);
			_composeAttributes->Add(_firstComposeAttribute);
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
			if (_type == 0)
			{
				for (int i = _composeAttributes->Count - 1; i >= 0; i--)
				{
					_composeAttributes[i]->InsertToDb();
				}
			}

			String^ columns = "ID,NAME_ATTR,COMPLEX_TYPE,START_COMPOSE_ATTR_ID,SELECT_TYPE,FIRST_SYMBOL_NUM,SYMBOL_COUNT,SPLIT_SYMBOLS,USE_PART,CREATE_USER,CREATE_DATE,SELECT_ATTR_ID";
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
			String^ sSelectAttrId;

			if (_type == 1)
			{
				selectType = _selectType + "";
				sSelectAttrId = _selectAttribute->Id + "";
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
				sSelectAttrId = "NULL";
			}


			String^ sQuery = String::Format("insert into {0}COMPLEX_ATTRS ({1}) values ({2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13})",
				_odbc->schema, columns, _id, sName, _type, sComposeID, selectType, firstSymbol, symbolCount, splitSymbols, usePart, sqlUser, sqlDate, sSelectAttrId);
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

		String^ GetValue(Dictionary<Attribute^, String^>^ attrValues)
		{
			if (_type == 0)
			{
				if (_composeAttributes == nullptr || _composeAttributes->Count <= 0)
				{
					SetComposeAttrs();
				}
				return GetComposeValue(attrValues);
			}
			else
			{
				if (_selectAttribute == nullptr)
				{
					SetSelectAttr();
				}
				if (_selectType == 0)
				{
					return GetNsymbolValue(attrValues);
				}
				else
				{
					return GetSplitValue(attrValues);
				}
			}
			return String::Empty;
		}

		List<Attribute^>^ GetParticipateAttributes()
		{
			List<Attribute^>^ list = gcnew List<Attribute ^>();
			if (_type == 0)
			{
				if (_composeAttributes == nullptr || _composeAttributes->Count <= 0)
				{
					SetComposeAttrs();
					for each (ComposeAttribute^ composeAttr in _composeAttributes)
					{
						if (composeAttr->Attribut != nullptr)
						{
							list->Add(composeAttr->Attribut);
						}
					}
				}
			}
			else
			{
				list->Add(SelectAttribute);
			}
			return list;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ComplexAttribute() 
		{

		}

		private:

			void SetSelectAttr()
			{
				_selectAttribute = gcnew Attribute(_selectAttributeId, _odbc);
			}

			String^ GetComposeValue(Dictionary<Attribute^, String^>^ attrValues)
			{
				String^ composeValue = String::Empty;
				for each (ComposeAttribute^ compAttr in _composeAttributes)
				{
					if (compAttr->HasStringValue)
					{
						composeValue += compAttr->StringValue;
					}
					else
					{
						composeValue += attrValues[compAttr->Attribut];
					}
				}
				return composeValue;
			}

			String^ GetSplitValue(Dictionary<Attribute^, String^>^ attrValues)
			{
				String^ value = attrValues[_selectAttribute];
				if (String::IsNullOrEmpty(value))
				{
					return value;
				}
				
				array<String^, 1>^ arrSymbols = gcnew array<String^, 1>(_symbols->Length);
				for (int i = 0; i < _symbols->Length; i++)
				{
					arrSymbols[i] = _symbols->Substring(i, 1);
				}

				array<String^, 1>^ splitArray = value->Split(arrSymbols, StringSplitOptions::RemoveEmptyEntries);

				if (_iSelectPart > splitArray->Length - 1)
				{
					return String::Empty;
				}
				return splitArray[_iSelectPart];
			}

			String^ GetNsymbolValue(Dictionary<Attribute^, String^>^ attrValues)
			{
				String^ value = attrValues[_selectAttribute];
				if (String::IsNullOrEmpty(value))
				{
					return value;
				}

				// для отсчета с нуля
				int iSym = _iFirstSymbol - 1;
				if (iSym > value->Length - 1 || iSym + _nCol > value->Length)
				{
					return String::Empty;
				}
				return value->Substring(iSym, _nCol);
			}
			

			void SetComposeAttrs()
			{
				_firstComposeAttribute = gcnew ComposeAttribute(_odbc, _firstComposeAttrId);

				ComposeAttribute^ nextComposeAttr;
				if (_firstComposeAttribute != nullptr)
				{
					_composeAttributes = gcnew List<ComposeAttribute ^>();
					_composeAttributes->Add(_firstComposeAttribute);

					nextComposeAttr = _firstComposeAttribute->NextAttribute;
					while (nextComposeAttr != nullptr)
					{
						_composeAttributes->Add(nextComposeAttr);
						nextComposeAttr = nextComposeAttr->NextAttribute;
					}
				}
			}

	};
}