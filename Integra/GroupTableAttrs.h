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
	public ref class GroupTableAttrs 
	{
	public:

	private:
		OdbcClass^ _odbc;

		int _id;


	public:

		GroupTableAttrs(OdbcClass^ odbc, String^ value)
		{
			_odbc = odbc;
			
		}




	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GroupTableAttrs() 
		{

		}


	};
}