#pragma once

#include "ODBCclass.h"
#include "AutoIntegration.h"

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
	public ref class AutoIntegrationManager
	{
	private:
		OdbcClass^ _odbc;
		String^ _driver;

		List<AutoIntegration^>^ _autoInts;

	public:
		AutoIntegrationManager(array<System::String ^> ^args) 
		{
			if (args != nullptr && args->Length > 0)
			{
				_driver = args[0];
				_odbc = gcnew OdbcClass(_driver);
			}
			
		}

		void StartService()
		{
			if (_odbc == nullptr)
			{
				MessageBox::Show("Ошибка! Драйвер соединения не подходит для модуля автоматической интеграции! Модуль не запущен!");
				return;
			}

			while (true)
			{
				SetAutoIntegrations();
				for each (AutoIntegration^ autoInt in _autoInts)
				{
					if (autoInt->IsOn)
					{
						DateTime^ now = DateTime::Now;
						DateTime^ nextStartDate = GetNextStartDate(autoInt->StartPeriod, autoInt->LastStart);

						if (autoInt->LastStart == nullptr || nextStartDate->CompareTo(now) < 0)
						{
							if (autoInt->StartTime->Hour == now->Hour && autoInt->StartTime->Minute == now->Minute)
							{
								StartIntegration(autoInt->SchemaId);
							}
						}
					}
				}

				Thread::Sleep(30000);
			}
		}

	private:

		void SetAutoIntegrations()
		{
			_autoInts = AutoIntegration::GetAllAutoIntegrations(_odbc);
		}

		DateTime^ GetNextStartDate(int periodType, DateTime^ lastStartDate)
		{
			if (lastStartDate == nullptr)
			{
				return nullptr;
			}

			if (periodType == 0)
			{
				DateTime^ nextStartDate = lastStartDate->AddDays(1);
				return nextStartDate;
			}
			else if (periodType == 1)
			{
				DateTime^ nextStartDate = lastStartDate->AddDays(7);
				return nextStartDate;
			}
			else if (periodType == 2)
			{
				DateTime^ nextStartDate = lastStartDate->AddMonths(1);
				return nextStartDate;
			}
			else if (periodType == 3)
			{
				DateTime^ nextStartDate = lastStartDate->AddMonths(3);
				return nextStartDate;
			}
			DateTime^ nextStartDate = lastStartDate->AddYears(1);
			return nextStartDate;
		}
		
		void StartIntegration(int schemaId)
		{
			String^ fullPath = Path::Combine(Application::StartupPath, "autoIntegrationTemplate.exe");
			if (File::Exists(fullPath))
			{
				String^ args = String::Format("\"{0}\" {1}", _driver, schemaId);
				Process::Start(fullPath, args);
			}
			else
			{
				MessageBox::Show("Ошибка! Файл-шаблон автоматической интеграции не найден!");
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AutoIntegrationManager() 
		{

		}
	};
}