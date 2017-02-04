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
		int _type;

		List<ComposeAttribute^>^ _composeAttributes;

		Attribute^ _selectAttribute;
		int _selectType;
		int _iFirstSymbol;
		int _nCol;
		String^ _symbols;
		int _iSelectPart;


	public:

		ComplexAttribute(OdbcClass^ odbc, Attribute^ recAttribute, String^ name)
		{
			_odbc = odbc;
			_name = name;
			_recAttribute = recAttribute;
			_composeAttributes = gcnew List<ComposeAttribute ^>();
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
			composeAttribute->AddNextAttribute(attribute);
			_composeAttributes->Add(composeAttribute);
		}

		void AddNextComposeAttr(String^ value)
		{
			ComposeAttribute^ composeAttribute = gcnew ComposeAttribute(_odbc, value);
			composeAttribute->AddNextAttribute(value);
			_composeAttributes->Add(composeAttribute);
		}

		void AddSelectParams(Attribute^ selectAttribute, int selectType)
		{
			_selectAttribute = selectAttribute;
			_selectType = selectType;
		}

		void AddFirstSymbolAndCol(int iFirstSymbol, int nCol)
		{
			_iFirstSymbol = iFirstSymbol;
			_nCol = nCol;
		}

		void AddSplitParams(String^ symbols, int iSelectPart)
		{
			_symbols = symbols;
			_iSelectPart = iSelectPart;
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