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

	public:
		DbPosition(String^ id, String^ fieldIdCode, List<Attribute^>^ attributeList, OdbcClass^ odbc) 
		{
			_odbc = odbc;
			_unicId = id;
			AttrIdCode = fieldIdCode;
			_attributeList = attributeList;
			SetAttrs(_attributeList);
		}

		DbPosition(String^ id, String^ fieldIdCode, List<Attribute^>^ attributeList, Dictionary<Attribute^, String^>^ attributes) 
		{
			_unicId = id;
			AttrIdCode = fieldIdCode;
			_attributeList = attributeList;
			_attributes = attributes;
		}

		DbPosition(List<Object^>^ attrs, List<Attribute^>^ attrNames, int iId, int iTitle) 
		{
			_unicId = attrs[iId]->ToString();
			AttrIdCode = attrNames[iId]->FullCode;
			Caption = attrs[iTitle]->ToString();
			_attributeList = attrNames;

			_attributes = gcnew Dictionary<Attribute^, String^>();
			for (int i = 0; i < attrs->Count; i++)
			{
				_attributes->Add(attrNames[i], attrs[i]->ToString());
			}
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
				String^ sQuery = String::Format("select {0} from {1} where {2} = \'{3}\'", attr->FullCode, attr->FullTable, AttrIdCode, UnicId);
				List<Object^>^ value = _odbc->ExecuteQuery(sQuery);
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