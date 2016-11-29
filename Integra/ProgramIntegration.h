#pragma once
#include "SystemSettings.h"
#include "BookSettings.h"
#include "IntegrationSettings.h"
#include "ODBCclass.h"
#include "Integration.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс для р
	/// </summary>
	public ref class ProgramIntegration
	{

	public:
		static OdbcClass^ Odbc;

		static List<Position^>^ SourceNew;
		static List<Position^>^ TargetNew;
		static List<DifferencePosition^>^ Differences;


	private:
		static SystemSettings^ _accessSettings;
		static List<IntegrationSettings^>^ _inegrationSettings;

	public:
		ProgramIntegration(OdbcClass^ odbc) 
		{
			Odbc = odbc;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ProgramIntegration() 
		{

		}

	public:
		Void Start() 
		{
			
		}

		static Void StartIntegration(IntegrationSettings^ intSet) 
		{
			Integration^ integration = gcnew Integration(intSet, Odbc);
			integration->SetPositionsAndCompare();
			/*integration->SetPositions();
			integration->CompareAll();

			SourceNew = integration->SourceNew;
			TargetNew = integration->TargetNew;
			Differences = integration->Differences;*/
		}

		static Void StartIntegrationAsync(IntegrationSettings^ intSet) 
		{
			Integration^ integration = gcnew Integration(intSet, Odbc);
			integration->SetPositionsAndCompare();
			
		}

		static List<IntegrationSettings^>^ GetIntegrationParams() 
		{
			List<Object^>^ integrationIds = Odbc->ExecuteQuery("select ID from " + Odbc->schema + "INTEGRATION_PARAMS");
			_inegrationSettings = gcnew List<IntegrationSettings^>();
			for each (Object^ id in integrationIds)
			{
				int iid = Decimal::ToInt32((Decimal)id);
				IntegrationSettings^ settings = gcnew IntegrationSettings(iid, Odbc);
				_inegrationSettings->Add(settings);
			}
			return _inegrationSettings;
		}

		static Void SaveLogs()
		{
			Odbc->SaveLogs();
		}


	private:
		static Void SetConnection() 
		{
			OpenFileDialog^ dialog = gcnew OpenFileDialog();
			dialog->InitialDirectory = Application::StartupPath;
			dialog->Multiselect = false;
			dialog->DefaultExt = ".ini";
			dialog->Filter = "Файлы конфигурации (.ini)|*.ini";

			System::Windows::Forms::DialogResult result = dialog->ShowDialog();
			if (result != System::Windows::Forms::DialogResult::OK)
			{
				return;
			}
			_accessSettings = gcnew SystemSettings(dialog->FileName);
			Odbc = gcnew OdbcClass(_accessSettings->Driver);
		}
	};
}