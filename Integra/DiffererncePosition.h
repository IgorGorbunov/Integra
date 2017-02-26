#pragma once

#include "Attribute.h"
#include "Position.h"
#include "AttributePair.h"

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

		List<AttributePair^>^ EqualsAttrPair;
		List<AttributePair^>^ DifferencesAttrPair;

		String^ UnicId;
		String^ AttrFullCodeUnicId;
		String^ Caption;

		Position^ SPos;
		Position^ TPos;

	public:
		DifferencePosition(String^ unicId, Position^ sPos, Position^ tPos) 
		{
			UnicId = unicId;
			SPos = sPos;
			TPos = tPos;
			Differences = gcnew List<array<Object ^, 2> ^>();
			Equals = gcnew List<array<Object ^> ^>();

			EqualsAttrPair = gcnew List<AttributePair ^>();
			DifferencesAttrPair = gcnew List<AttributePair ^>();

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

		void AddDifferenceAttr(String^ sourceAttributeName, String^ sourceAttributeValue, String^ targetAttributeName, String^ targetAttributeValue) 
		{
			array<Object^, 2>^ arr = gcnew array<Object ^, 2>(2, 2);
			arr[0, 0] = sourceAttributeName;
			arr[0, 1] = sourceAttributeValue;
			arr[1, 0] = targetAttributeName;
			arr[1, 1] = targetAttributeValue;
			Differences->Add(arr);
		}

		void AddDifferenceAttr(AttributePair^ attributePair) 
		{
			DifferencesAttrPair->Add(attributePair);
		}

		void AddEqualAttr(Attribute^ sourceAttribute, Attribute^ targetAttribute, String^ value) 
		{
			array<Object^>^ arr = gcnew array<Object ^>(3);
			arr[0] = sourceAttribute;
			arr[1] = targetAttribute;
			arr[2] = value;
			Equals->Add(arr);
		}

		void AddEqualAttr(AttributePair^ attributePair) 
		{
			EqualsAttrPair->Add(attributePair);
		}


		void AddEqualAttr(String^ sourceAttributeName, String^ targetAttributeName, String^ value) 
		{
			array<Object^>^ arr = gcnew array<Object ^>(3);
			arr[0] = sourceAttributeName;
			arr[1] = targetAttributeName;
			arr[2] = value;
			Equals->Add(arr);
		}
	};
}