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

		static List<List<Object^>^>^ SourceTabNew;
		static List<List<Object^>^>^ TargetTabNew;

		static int NinSource;
		static int NinTarget;
		static int Nequal;
		static long Nmatches;

	private:
		static SystemSettings^ _accessSettings;
		static List<IntegrationSettings^>^ _inegrationSettings;
		static Integration^ _integration;

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
		static Void StartIntegrationTable(IntegrationSettings^ intSet, System::Windows::Forms::Form^% form, System::Windows::Forms::Label^% lblCount) 
		{
			_integration = gcnew Integration(intSet, Odbc);
			_integration->StartExactIntegration(form, lblCount);

			SourceNew = _integration->SourceNew;
			TargetNew = _integration->TargetNew;
			Differences = _integration->Differences;

			NinSource = _integration->NinSource;
			NinTarget = _integration->NinTarget;
			Nequal = _integration->Nequal;
			Nmatches = _integration->Nmatches;
		}

		static Void StartRoughIntegration(IntegrationSettings^ intSet) 
		{
			_integration = gcnew Integration(intSet, Odbc);
			_integration->StartRoughIntegration();
		}

		static void StopIntegration()
		{
			_integration->StopIntegration();
		}


		static void AddPosToSource(Position^ pos)
		{
			_integration->AddPosToSource(pos);
		}

		static void AddPosToTarget(Position^ pos)
		{
			_integration->AddPosToTarget(pos);
		}

		static void UpdatePosTarget(Position^ currentPos, Dictionary<Attribute^, String^>^ newAttrVals)
		{
			_integration->UpdatePosToTarget(currentPos, newAttrVals);
		}

		static void UpdatePosSource(Position^ currentPos, Dictionary<Attribute^, String^>^ newAttrVals)
		{
			_integration->UpdatePosToSource(currentPos, newAttrVals);
		}

		static void NoticeRemoveFromSource(Position^ currentPos)
		{
			_integration->NoticeRemoveFromSource(currentPos);
		}

		static void NoticeRemoveFromTarget(Position^ currentPos)
		{
			_integration->NoticeRemoveFromTarget(currentPos);
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

		static List<Object^>^ GetTableIntegrationParams() 
		{
			String^ columns = "INTEGRATION_PARAMS.ID, INTEGRATION_BOOK.ID.ID, INTEGRATION_BOOK.ID, INTEGRATION_BOOK.ID, INTEGRATION_BOOK.ID, INTEGRATION_BOOK.ID, INTEGRATION_BOOK.ID, INTEGRATION_PARAMS.ID, INTEGRATION_PARAMS.ID, INTEGRATION_PARAMS.ID, INTEGRATION_PARAMS.ID, ";
			
			String^ squery = String::Format("select INTEGRATION_PARAMS.ID, BOOK.ID, BOOK.NAME " + 
				"from {0}INTEGRATION_PARAMS, {0}BOOKS where INTEGRATION_PARAMS.BOOK_TYPE_ID = BOOK.ID", Odbc->schema);
			List<Object^>^ list = Odbc->ExecuteQuery(squery);
			return list;
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