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

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ComposeAttribute() 
		{

		}


	};
}