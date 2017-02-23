#pragma once

#include "Logger.h"
#include "Attribute.h"
#include "BookSettings.h"


namespace Integra {

	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;
	//using namespace SemanticCore;

	/// <summary>
	/// ����� posicii Semantic
	/// </summary>
	public ref class Position
	{
	public:
		property Dictionary<Attribute^, String^>^ AttributesAndValues
		{
			Dictionary<Attribute^, String^>^ get()
			{
				return _attributes;
			}
		}

		property String^ UnicId
		{
			String^ get()
			{
				return _unicId;
			}
		}
		property Attribute^ AttrId
		{
			Attribute^ get()
			{
				return _attrId;
			}
			void set(Attribute^ attr)
			{
				_attrId = attr;
			}
		}

		String^ Caption;

	protected:
		Dictionary<Attribute^, String^>^ _attributes;
		String^ _unicId;
		
		Attribute^ _attrId;
		String^ _attrIdCode;

	private:
		OdbcClass^ _odbc;
		BookSettings^ _intgrBook;

	public:
		Position(Object^ id, int idIntgrBook, OdbcClass^ odbc) 
		{
			//todo
			_odbc = odbc;
			_intgrBook = gcnew BookSettings(idIntgrBook, odbc);
			_attrId = _intgrBook->AttrId;
			Attribute^ attrCaption = _intgrBook->AttrCaption;
			String^ condition;
			if (attrCaption->DataType == "������")
			{
				condition = String::Format("where ATABLE.{0} = '{1}'", AttrId->Code, id);
			}
			else
			{
				condition = String::Format("where ATABLE.{0} = {1}", AttrId->Code, id);
			}
			Object^ oCaption = attrCaption->GetValue(condition, true, _intgrBook->Odbc);
			Caption = oCaption->ToString();
		}

		Position() 
		{

		}

		String^ GetValue(Attribute^ attribute)
		{
			if (_attributes->ContainsKey(attribute))
			{
				return _attributes[attribute];
			}
			else
			{
				return nullptr;
			}
		}


	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Position() 
		{

		}


	};
}