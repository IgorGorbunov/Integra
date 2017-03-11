#pragma once

#include "Logger.h"
#include "Semantic.h"
#include "Position.h"
#include "Attribute.h"

namespace Integra {

	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;
	//using namespace SemanticCore;

	/// <summary>
	/// Класс posicii Semantic
	/// </summary>
	public ref class SemanticPosition : Position
	{
	public:
		property bool IsGroup
		{
			bool get()
			{
				/*if (!_isGroup.HasValue)
				{
					ISCClass^ semClass = _element->ParentClass();
					ISCClass^ childClass = semClass->ChildClass();
					if (childClass == nullptr)
					{
						_isGroup = false;
					}
					else
					{
						_isGroup = true;
					}
				}*/
				return _isGroup.Value;
			}
		}
		property bool IsBook
		{
			bool get()
			{
				/*if (!_isBook.HasValue)
				{
					ISCClass^ semClass = _element->ParentClass();
					if (semClass == nullptr)
					{
						_isBook = true;
					}
					else
					{
						_isBook = false;
					}
				}*/
				return _isBook.Value;
			}
		}
		property int ChildCount
		{
			int get()
			{
				/*if (!_nChilds.HasValue)
				{
					if (_element->ChildListCount() > 1)
					{
						MessageBox::Show("!!!!!!!!!!!!!!!!!!!!!!");
					}
					SCChildList^ chList = _element->ChildListByIdx(0);
					_nChilds = chList->CountChildObjects;
				}*/
				return _nChilds.Value;
			}
		}


	private:
		//ISCObject^ _element;
		List<Attribute^>^ _attributeList;
		Attribute^ _attrIdCode;

		Nullable<bool> _isGroup;
		Nullable<bool> _isBook;
		Nullable<int> _nChilds;



	public:
		SemanticPosition(Object^ object, List<Attribute^>^ attributeList,  Attribute^ attrIdCode) 
		{
			/*_element = object;
			_attributeList = attributeList;
			_attrIdCode = attrIdCode;
			_unicId = GetAttrValue(attrIdCode);
			if (UnicId == "h796TXI1baNItPWYDTx7.d")
			{
			MessageBox::Show("test");
			}
			if (!IsBook && !IsGroup)
			{
			SetAttrs(_attributeList);
			}*/
			
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SemanticPosition() 
		{

		}

	public:
		List<Position^>^ GetChildPositions() 
		{
			List<Position^>^ list = gcnew List<Position ^>();
			/*int nChilds = _element->ChildListCount();
			for	(int i = 0; i < nChilds; i++)
			{
				SCChildList^ childList = _element->ChildListByIdx(i);
				int nObjs = childList->CountChildObjects;
				for (int j = 0; j < nObjs; j++)
				{
					ISCObject^ element = childList->ChildObjects[j];
					list->Add(gcnew SemanticPosition(element, _attributeList, _attrIdCode));
				}
			}*/
			return list;
		}

		virtual Dictionary<Attribute^, String^>^ GetRemakingAttrsAndVals(OdbcClass^ odbc) override
		{
			return nullptr;
		}

	private:
		Void SetAttrs(List<Attribute^>^ parametrCodes)
		{
			/*_attributes = gcnew Dictionary<Attribute^, String^>();
			for each(Attribute^ attr in parametrCodes)
			{
				String^ value = GetAttrValue(attr);
				if (value == nullptr)
				{
					_attributes->Add(attr, "");
				}
				else
				{
					_attributes->Add(attr, value);
				}
			}*/
		}

		String^ GetAttrValue(Attribute^ attribute)
		{
			if (attribute->IsService)
			{
				return GetServiceAttr(attribute->Code);
			} 
			else
			{
				//ISCClass^ cla = _element->ParentClass();
				//ISCClass^ cla2 = cla->ParentClass();
				//for (int i = 0; i < cla->CountAttrClasses; i++)
				//{
				//	ISCClassAttribute^ classAttr = cla->AttrClassByIndex(i);
				//	classAttr->IsGroupUsed[cla2->GuidClass] = true;

				//}



				//String^ guid = _element->ObjectGUID;
				//int nAttrs = _element->CountAttrs();
				//String^ ss = "";
				//for (int i = 0; i < _element->CountAttrs(); i++)
				//{
				//	ss += _element->AttrObjectByIndex(i)->NameAttr + " - " + _element->AttrObjectByIndex(i)->TextValue;
				//}
				//

				//String^ code = ;
				/*SCAttribute^ attr = _element->AttrObjectByNameAttr(attribute->Code);
				if (attr == nullptr)
				{
					return nullptr;
				}
				String^ s = attr->TextValue;
				return attr->TextValue;*/
			}
			return nullptr;
		}

		String^ GetServiceAttr(String^ code)
		{
			/*if (code == "^GUID")
			{
				return _element->ObjectGUID;
			}*/
			return nullptr;
		}
	};
}