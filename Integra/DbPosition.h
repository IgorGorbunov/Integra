#pragma once

#include "Position.h"
#include "ODBCclass.h"

namespace Integra {

	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;

	/// <summary>
	/// Класс posicii Semantic
	/// </summary>
	public ref class DbPosition : Position
	{

	private:
		OdbcClass^ _odbc;
		List<Attribute^>^ _attributeList;
		String^ _fieldIdCode;

	public:
		DbPosition(String^ id, String^ fieldIdCode, List<Attribute^>^ attributeList, OdbcClass^ odbc) 
		{
			_odbc = odbc;
			_unicId = id;
			_fieldIdCode = fieldIdCode;
			_attributeList = attributeList;
			SetAttrs(_attributeList);
		}

		DbPosition(String^ id, String^ fieldIdCode, List<Attribute^>^ attributeList, Dictionary<Attribute^, String^>^ attributes) 
		{
			_unicId = id;
			_fieldIdCode = fieldIdCode;
			_attributeList = attributeList;
			_attributes = attributes;
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DbPosition() 
		{

		}

	private:
		Void SetAttrs(List<Attribute^>^ parametrCodes)
		{
			_attributes = gcnew Dictionary<Attribute^, String^>();
			for each(Attribute^ attr in parametrCodes)
			{
				List<Object^>^ value = _odbc->ExecuteQuery("select " + attr->Code + " from " + attr->FullTable + " where " + _fieldIdCode + " = \'" + UnicId + "\'");
				if (value[0] == nullptr && String::IsNullOrEmpty(value[0]->ToString()))
				{
					_attributes->Add(attr, "");
				}
				else
				{
					_attributes->Add(attr, value[0]->ToString());
				}
			}
		}

	};
}