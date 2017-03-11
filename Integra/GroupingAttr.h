#pragma once

#include "Logger.h"
#include "Attribute.h"


namespace Integra {

	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;



	public ref class GroupingAttr
	{
	public:
		property String^ Title
		{
			String^ get()
			{
				return _title;
			}
		}
		property String^ Value
		{
			String^ get()
			{
				return _value;
			}
		}
		property String^ DataType
		{
			String^ get()
			{
				if (_valuePosAttr == nullptr)
				{
					return nullptr;
				}
				return _valuePosAttr->DataType;
			}
		}

		property Attribute^ GrAttrTitle
		{
			Attribute^ get()
			{
				return _titleGrAttr;
			}
		}
	
	private:
		Attribute^ _titlePosAttr;
		Attribute^ _valuePosAttr;
		Attribute^ _titleGrAttr;
		Attribute^ _nameGrAttr;

		String^ _title;
		String^ _name;
		String^ _value;

	public:

		static String^ GetValueByGrAttribute(Attribute^ grTitleAttr, List<GroupingAttr^>^ grAttrs)
		{
			for each (GroupingAttr^ grAttr in grAttrs)
			{
				if (grTitleAttr == grAttr->GrAttrTitle)
				{
					return grAttr->Value;
				}
			}
			return nullptr;
		}

		static String^ GetDataTypeByGrAttribute(Attribute^ grTitleAttr, List<GroupingAttr^>^ grAttrs)
		{
			for each (GroupingAttr^ grAttr in grAttrs)
			{
				if (grTitleAttr == grAttr->GrAttrTitle)
				{
					return grAttr->DataType;
				}
			}
			return nullptr;
		}

		GroupingAttr(Attribute^ titleGrAttr, Attribute^ nameGrAttr, String^ title, String^ name) 
		{
			_titleGrAttr = titleGrAttr;
			_nameGrAttr = nameGrAttr;
			_title = title;
			_name = name;
		}

		void AddPosValue(Attribute^ titlePosAttr, Attribute^ valuePosAttr, String^ value)
		{
			_titlePosAttr = titlePosAttr;
			_valuePosAttr = valuePosAttr;
			_value = value;
		}

		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GroupingAttr() 
		{

		}

	};
}
