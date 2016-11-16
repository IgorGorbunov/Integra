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
	/// Класс posicii Semantic
	/// </summary>
	public ref class SemanticPositionCollection : PositionCollection
	{


	public:
		SemanticPositionCollection() 
		{

		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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