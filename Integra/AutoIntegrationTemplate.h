#pragma once

#include "ODBCclass.h"


namespace Integra {

	using namespace System;
	using namespace System::Threading;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Класс для р
	/// </summary>
	public ref class AutoIntegrationTemplate
	{
	private:
		OdbcClass^ _odbc;
		String^ _driver;

		int _schemaId;
		


	public:
		AutoIntegrationTemplate(array<System::String ^> ^args) 
		{
			if (args != nullptr && args->Length > 0)
			{
				_driver = args[0];
				_odbc = gcnew OdbcClass(_driver);
				_schemaId = int::Parse(args[1]);
			}
		}

		void StartIntegration()
		{
			if (_odbc == nullptr || _schemaId == -1)
				return;

			IntegrationSettings^ intSet = gcnew IntegrationSettings(_schemaId, _odbc);
			ProgramIntegration::StartAutoIntegration(intSet, _odbc);
		}


	private:



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AutoIntegrationTemplate() 
		{

		}
	};
}