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
	public ref class GroupTablePair 
	{
	public:


	private:
		OdbcClass^ _odbc;

		int _id;
		Attribute^ _titleAttr;
		Attribute^ _nameAttr;


	public:

		GroupTablePair(OdbcClass^ odbc, Attribute^ titleAttr, Attribute^ nameAttr)
		{
			_odbc = odbc;
			_titleAttr = titleAttr;
			_nameAttr = nameAttr;
		}

	public:
		static void SetPairs(int groupParamsId)
		{
			String^ columns = "ID,ID_TITLE,ID_NAME,ID_GROUP_PARAMS,CREATE_USER,CREATE_DATE";

		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GroupTablePair() 
		{

		}


	};
}