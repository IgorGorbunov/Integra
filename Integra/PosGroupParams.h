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
	public ref class PosGroupParam 
	{
	public:


	private:
		OdbcClass^ _odbc;
		int _id;
		int _idIntegrationBook;

		Dictionary<Attribute^, Attribute^>^ _attrs;

	public:

		PosGroupParam(Dictionary<Attribute^, Attribute^>^ attrs)
		{
			_attrs = attrs;
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PosGroupParam() 
		{

		}

	private:

	};
}