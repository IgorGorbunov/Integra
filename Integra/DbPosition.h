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
		/*DbPosition(String^ id, String^ fieldIdCode, List<Attribute^>^ attributeList, OdbcClass^ odbc) 
		{
			_odbc = odbc;
			_unicId = id;
			_attrIdCode = fieldIdCode;
			_attributeList = attributeList;
			SetAttrs(_attributeList);
		}*/

		DbPosition(String^ id, Attribute^ attrId, List<Attribute^>^ attributeList, OdbcClass^ odbc, BookSettings^ intgrBook) 
		{
			_intgrBook = intgrBook;
			_odbc = odbc;
			_unicId = id;
			AttrId = attrId;
			_attributeList = attributeList;
			SetAttrs(_attributeList);
		}

		/*DbPosition(String^ id, String^ fieldIdCode, List<Attribute^>^ attributeList, Dictionary<Attribute^, String^>^ attributes) 
		{
			_unicId = id;
			_attrIdCode = fieldIdCode;
			_attributeList = attributeList;
			_attributes = attributes;
		}*/

		DbPosition(String^ id, Attribute^ attrId, List<Attribute^>^ attributeList, Dictionary<Attribute^, String^>^ attributes, BookSettings^ intgrBook) 
		{
			_intgrBook = intgrBook;
			_unicId = id;
			AttrId = attrId;
			_attributeList = attributeList;
			_attributes = attributes;
			
		}

		DbPosition(List<Object^>^ attrs, List<Attribute^>^ attrNames, int iId, int iTitle, BookSettings^ intgrBook) 
		{
			_intgrBook = intgrBook;
			_unicId = attrs[iId]->ToString();
			AttrId = attrNames[iId];
			Caption = attrs[iTitle]->ToString();
			_attributeList = attrNames;

			_attributes = gcnew Dictionary<Attribute^, String^>();
			for (int i = 0; i < attrs->Count; i++)
			{
				_attributes->Add(attrNames[i], attrs[i]->ToString());
			}
		}

		virtual void SetEquivAttr(Attribute^ equivAttr) override
		{
			_attrEq = equivAttr;
			String^ sqlId = _odbc->GetSqlValue(_attrEq->DataType, _unicId);
			String^ condition = String::Format("where ATABLE.{0} = {1}", AttrId->Code, sqlId);

			Object^ equiv = _attrEq->GetValue(condition, true, _intgrBook->Odbc);
			_eqValue = equiv->ToString()->Trim();
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
				//todo datatype
				String^ sQuery = String::Format("select {0} from {1} where {2} = \'{3}\'", attr->FullCode, attr->FullTable, AttrId->Code, UnicId);
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