#pragma once

#include "Logger.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;
	using namespace SemanticCore;

	/// <summary>
	/// ����� posicii Semantic
	/// </summary>
	public ref class SemanticPositionCollection : PositionCollection
	{


	public:
		SemanticPositionCollection() 
		{

		}


	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~SemanticPositionCollection() 
		{

		}

	public:
		Void override SetAllPositions() 
		{

		}
	};
}