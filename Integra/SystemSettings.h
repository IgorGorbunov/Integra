#pragma once

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс для работы с настройками систем
	/// </summary>
	public ref class SystemSettings 
	{
	public:
		property String^ Driver
		{
			String^ get()
			{
				if (String::IsNullOrEmpty(_driver))
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

	private:
		String^ _filePath;
		Dictionary<String^, String^>^ _properties;
		String^ _driver;

	public:
		SystemSettings(String^ filePath) 
		{
			_filePath = filePath;
			ReadIniFile();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SystemSettings() 
		{

		}


	private: Void ReadIniFile(Void) 
			 {
				 StreamReader^ reader = gcnew StreamReader(_filePath, Encoding::UTF8);
				 try
				 {
					 _properties = gcnew Dictionary<String ^, String ^>();
					 while (!reader->EndOfStream)
					 {
						 String^ line = reader->ReadLine();
						 if (line[0] == '#')
							 continue;

						 if (line[0] == '$')
						 {
							 String^ value = reader->ReadLine();
							 String^ word = line->Substring(1)->Trim()->ToUpper();
							 _properties->Add(word, value);
						 }
					 }
				 }
				 finally
				 {
					 reader->Close();
				 }
			 }

	};
}