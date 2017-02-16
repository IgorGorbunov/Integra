#pragma once

#include "BookSettings.h"
#include "Book.h"
#include "DbBook.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс 
	/// </summary>
	public ref class GroupParam
	{
	public:

	private:
		String^ _code;
		Attribute^ _codeAttr;
		String^ _name;
		Attribute^ _nameAttr;

	public:
		GroupParam(String^ code, Attribute^ codeAttr, String^ name, Attribute^ nameAttr)
		{
			_code = code;
			_name = name;
			_codeAttr = codeAttr;
			_nameAttr = nameAttr;
		}


		static List<GroupParam^>^ GetGroupParams(BookSettings^ settingsBook, OdbcClass^ odbc, Dictionary<Attribute^, Attribute^>^ grAttrs, Dictionary<Attribute^, Attribute^>^ posAttrs)
		{
			Book^ book = gcnew DbBook(settingsBook, nullptr, true, odbc);
			List<GroupParam^>^ list = gcnew List<GroupParam ^>();

			for each (KeyValuePair<Attribute^, Attribute^>^ pairGr in grAttrs)
			{
				String^ code = book->GetAttrValue(pairGr->Key)->ToString()->Trim();
				String^ name = book->GetAttrValue(pairGr->Value)->ToString()->Trim();

				list->Add(gcnew GroupParam(code, pairGr->Key, name, pairGr->Value));
			}
			return list;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GroupParam() 
		{

		}


	};
}