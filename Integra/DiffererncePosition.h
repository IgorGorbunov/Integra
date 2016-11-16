#pragma once

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
	public ref class DifferencePosition
	{

	public:
		List<array<Object^, 2>^>^ Differences;
		List<array<Object^>^>^ Equals;
		String^ UnicId;

	public:
		DifferencePosition(String^ unicId) 
		{
			UnicId = unicId;
			Differences = gcnew List<array<Object ^, 2> ^>();
			Equals = gcnew List<array<Object ^> ^>();
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DifferencePosition() 
		{

		}

	public:
		void AddDifferenceAttr(Attribute^ sourceAttribute, String^ sourceAttributeValue, Attribute^ targetAttribute, String^ targetAttributeValue) 
		{
			array<Object^, 2>^ arr = gcnew array<Object ^, 2>(2, 2);
			arr[0, 0] = sourceAttribute;
			arr[0, 1] = sourceAttributeValue;
			arr[1, 0] = targetAttribute;
			arr[1, 1] = targetAttributeValue;
			Differences->Add(arr);
		}

		void AddEqualAttr(Attribute^ sourceAttribute, Attribute^ targetAttribute, String^ value) 
		{
			array<Object^>^ arr = gcnew array<Object ^>(3);
			arr[0] = sourceAttribute;
			arr[1] = targetAttribute;
			arr[2] = value;
			Equals->Add(arr);
		}
	};
}