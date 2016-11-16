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
	public ref class PositionCollection
	{

	private:
		List<Position^>^ _positions;

	public:
		PositionCollection() 
		{

		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PositionCollection() 
		{

		}

	public:
		Void abstract SetAllPositions() 


	};
}