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
	/// ����� posicii Semantic
	/// </summary>
	public ref class Position
	{
	public:
		property Dictionary<Attribute^, String^>^ Attributes
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

	protected:
		Dictionary<Attribute^, String^>^ _attributes;
		String^ _unicId;

	public:
		Position() 
		{

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