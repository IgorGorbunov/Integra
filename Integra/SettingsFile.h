#pragma once

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Класс для работы с настройками 
	/// </summary>
	public ref class SettingsFile
	{
	protected:
		Dictionary<String^, String^>^ _properties;

	private:
		String^ _filePath;
		List<String^>^ _lines;


	public:
		SettingsFile(String^ filePath) 
		{
			_filePath = filePath;
			ReadIniFile();
		}

		Void SetValue(String^ code, String^ value)
		{
			if (_properties != nullptr && _properties->ContainsKey(code))
			{
				_properties[code] = value;
			}
		}

		Void UpdateFile()
		{
			StreamWriter^ writer = gcnew StreamWriter(_filePath, false, Encoding::UTF8);
			try
			{
				String^ value;
				for each(String^ s in _lines)
				{
					if (String::IsNullOrEmpty(s))
					{
						continue;
					}
					if (s[0] == '#')
					{
						writer->WriteLine(s);
						continue;
					}
					if (s[0] == '$')
					{
						value = _properties[s->Substring(1)->ToUpper()];
						writer->WriteLine(s);
					}
					else
					{
						if (value != nullptr)
						{
							writer->WriteLine(value);
						}
						else
						{
							writer->WriteLine(s);
						}
					}
				}
			}
			finally
			{
				writer->Flush();
				writer->Close();
			}
		}


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SettingsFile() 
		{

		}


	Void ReadIniFile(Void) 
			 {
				 _lines = gcnew List<String ^>();
				 StreamReader^ reader;
				 try
				 {
					 reader = gcnew StreamReader(_filePath, Encoding::UTF8);
					 _properties = gcnew Dictionary<String ^, String ^>();
					 String^ word = "";
					 while (!reader->EndOfStream)
					 {
						 String^ line = reader->ReadLine();
						 _lines->Add(line);
						 if (line[0] == '#')
							 continue;
						 if (line[0] == '$')
						 {
							 word = line->Substring(1)->Trim()->ToUpper();
							 continue;
						 }
						 if (!String::IsNullOrEmpty(word))
						 {
							 _properties->Add(word, line);
							 word = "";
						 }
					 }
				 }
				 catch(System::IO::FileNotFoundException^)
				 {

				 }
				 finally
				 {
					 if (reader != nullptr)
					 {
						 reader->Close();
					 }
				 }
			 }

	};
}