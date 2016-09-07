#pragma once

namespace Integra {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Globalization;
	using namespace System::Text;
	using namespace System::IO;

	/// <summary>
	/// Класс логгирования
	/// </summary>
	public ref class Logger 
	{

	private:
		StreamWriter^ _writer;

		String^ _name;
		String^ _ext;
		int _nFiles;
		long _maxFileSize; // ~ мегабайт

	public:
		Logger(Void) 
		{
			Logger("Logger", ".log");
		}

		Logger(String^ fileName, String^ extension)
		{
			_nFiles = 5;
			_maxFileSize = 1000000l;

			_name = fileName;
			if (extension[0] == '.')
			{
				_ext = extension;
			} 
			else
			{
				_ext = '.' + extension;
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Logger() 
		{

		}

	public:
		Void WriteLine(Object^ line)
		{
			try
			{
				SetFile();
				_writer->WriteLine(DateTime::Now + Environment::NewLine + line + Environment::NewLine);
				_writer->Flush();
			}
			finally
			{
				_writer->Close();
			}
		}

		Void WriteError(Object^ error)
		{
			String^ message = "*--*--*--*--*--*--*--*--*--*" +
				Environment::NewLine + error;
			WriteLine(message);
		}

	private:
		Void SetFile(Void)
		{
			String^ currentFile = AppDomain::CurrentDomain->BaseDirectory + _name + _ext;
			try
			{
				FileInfo^ info = gcnew FileInfo(currentFile);
				bool append = true;
				if (info->Length > _maxFileSize)
				{
					CopyFiles();
					append = false;
				}

				_writer = gcnew StreamWriter(currentFile, append, Encoding::UTF8);
			}
			catch (FileNotFoundException^)
			{
				_writer = gcnew StreamWriter(currentFile, false, Encoding::UTF8);
			}        
		}

		void CopyFiles(Void)
		{
			for (int i = _nFiles; i > 2; i--)
			{
				try
				{
					FileInfo^ f = gcnew FileInfo(AppDomain::CurrentDomain->BaseDirectory + _name +
						(i - 1) + _ext);
					f->CopyTo(AppDomain::CurrentDomain->BaseDirectory + _name + i + _ext, true);
				}
				catch (FileNotFoundException^ ) { }

			}

			FileInfo^ firstFile = gcnew FileInfo(AppDomain::CurrentDomain->BaseDirectory + _name + _ext);
			firstFile->CopyTo(AppDomain::CurrentDomain->BaseDirectory + _name + "2" + _ext, true);
		}



	};
}