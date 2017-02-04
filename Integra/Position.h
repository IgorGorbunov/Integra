#pragma once

#include "Logger.h"
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

		String^ AttrIdCode;

		String^ Caption;

	protected:
		Dictionary<Attribute^, String^>^ _attributes;
		String^ _unicId;
		

	public:
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Position() 
		{

		}


	};
}