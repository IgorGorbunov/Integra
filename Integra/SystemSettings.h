#pragma once

#include "SettingsFile.h"

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс для работы с настройками систем
	/// </summary>
	public ref class SystemSettings : public SettingsFile
	{
	public:
		property String^ Driver
		{
			String^ get()
			{
				if (_properties != nullptr && String::IsNullOrEmpty(_driver))
				{
					if (_properties->ContainsKey("DRIVER"))
					{
						_driver = _properties["DRIVER"];
					}
					else
					{
						return nullptr;
					}
				} 
				return _driver;
			}
		}
		property String^ Login
		{
			String^ get()
			{
				if (String::IsNullOrEmpty(_login))
				{

					if (_properties != nullptr && _properties->ContainsKey("LOGIN"))
					{
						_login = _properties["LOGIN"];
					}
					else
					{
						return nullptr;
					}
				} 
				return _login;
			}
		}

	private:
		String^ _driver;
		String^ _login;

	public:
		SystemSettings(String^ filePath) : SettingsFile(filePath)
		{

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SystemSettings() 
		{

		}


	};
}