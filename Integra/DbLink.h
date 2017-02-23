#pragma once

#include "ODBCclass.h"
#include "Attribute.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class DbLink 
	{

	private:
		OdbcClass^ _odbc;
		Attribute^ _firstAttribute;
		Attribute^ _secondAttribute;
		


	public:

		DbLink(Attribute^ firstAttribute, Attribute^ secondAttribute)
		{
			_firstAttribute = firstAttribute;
			_secondAttribute = secondAttribute;
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbLink() 
		{

		}


	};
}