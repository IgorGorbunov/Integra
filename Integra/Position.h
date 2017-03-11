#pragma once

#include "Logger.h"
#include "Attribute.h"
#include "BookSettings.h"
#include "GroupingAttr.h"


namespace Integra {

	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;
	//using namespace SemanticCore;

	/// <summary>
	/// Класс posicii Semantic
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
		property List<GroupingAttr^>^ GroupingAttrs
		{
			List<GroupingAttr^>^ get()
			{
				return _groupingAttrs;
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
		property Attribute^ AttrName
		{
			Attribute^ get()
			{
				return _attrName;
			}
			void set(Attribute^ attr)
			{
				_attrName = attr;
			}

		}
		property String^ EqualValue
		{
			String^ get()
			{
				return _eqValue;
			}
		}


		String^ Caption;

	protected:
		BookSettings^ _intgrBook;

		Dictionary<Attribute^, String^>^ _attributes;
		List<GroupingAttr^>^ _groupingAttrs;

		Attribute^ _attrName;
		Attribute^ _attrId;
		String^ _unicId;

		Attribute^ _attrEq;
		String^ _eqValue;
		
		String^ _attrIdCode;

		Object^ _id;

	private:
		OdbcClass^ _odbc;
		
	public:
		Position(Object^ id, int idIntgrBook, OdbcClass^ odbc) 
		{
			//todo
			_id = id;
			_odbc = odbc;
			_intgrBook = gcnew BookSettings(idIntgrBook, odbc);
			_attrId = _intgrBook->AttrId;
			
			SetCaption();
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

		virtual void SetEquivAttr(Attribute^ equivAttr)
		{

		}

		virtual Dictionary<Attribute^, String^>^ GetRemakingAttrsAndVals(OdbcClass^ odbc)
		{
			return nullptr;
		}

		void AddGroupingAttr(GroupingAttr^ groupingAttr)
		{
			if (_groupingAttrs == nullptr)
			{
				_groupingAttrs = gcnew List<GroupingAttr ^>();
			}
			_groupingAttrs->Add(groupingAttr);
		}

		void AddValueToGroupingAttr(Attribute^ titlePosAttr, Attribute^ valuePosAttr, String^ title, String^ value)
		{
			for each (GroupingAttr^ groupAttr in _groupingAttrs)
			{
				if (title == groupAttr->Title)
				{
					groupAttr->AddPosValue(titlePosAttr, valuePosAttr, value);
					break;
				}
			}
		}

		List<GroupingAttr^>^ GetGroupAttrsCopy()
		{
			return gcnew List<GroupingAttr^>(_groupingAttrs);
		}

		void SetGroupingAttrs(List<GroupingAttr^>^ groupingAttrs)
		{
			_groupingAttrs = groupingAttrs;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Position() 
		{

		}

	private:
		void SetCaption()
		{
			if (_intgrBook->IsSemantic)
			{
				
			}
			else
			{
				Attribute^ attrCaption = _intgrBook->AttrCaption;
				String^ condition;
				if (attrCaption->DataType == "СТРОКА")
				{
					condition = String::Format("where ATABLE.{0} = '{1}'", AttrId->Code, _id);
				}
				else
				{
					condition = String::Format("where ATABLE.{0} = {1}", AttrId->Code, _id);
				}
				Object^ oCaption = attrCaption->GetValue(condition, true, _intgrBook->Odbc);
				if (oCaption == nullptr)
				{
					Caption = String::Empty;
				}
				else
				{
					Caption = oCaption->ToString();
				}
				
			}
		}

	};
}