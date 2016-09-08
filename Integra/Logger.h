#pragma once

#include "NetCopy.h"

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

		String^ _currentFileName;
		String^ _folder;
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
			_folder = "Logs";

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
			NetCopy::CopyToMe(_currentFileName);
		}

	private:
		Void SetFile(Void)
		{
			_currentFileName = Path::Combine(AppDomain::CurrentDomain->BaseDirectory, _folder, _name + _ext);
			try
			{
				FileInfo^ info = gcnew FileInfo(_currentFileName);
				bool append = true;
				if (info->Length > _maxFileSize)
				{
					CopyFiles();
					append = false;
				}

				_writer = gcnew StreamWriter(_currentFileName, append, Encoding::UTF8);
			}
			catch (FileNotFoundException^)
			{
				String^ dir = Path::Combine(AppDomain::CurrentDomain->BaseDirectory, _folder);
				if (!Directory::Exists(dir))
				{
					Directory::CreateDirectory(dir);
				}
				_writer = gcnew StreamWriter(_currentFileName, false, Encoding::UTF8);
			}        
		}

		void CopyFiles(Void)
		{
			for (int i = _nFiles; i > 2; i--)
			{
				try
				{
					FileInfo^ f = gcnew FileInfo(Path::Combine(AppDomain::CurrentDomain->BaseDirectory, _folder, _name +
						(i - 1) + _ext));
					f->CopyTo(Path::Combine(AppDomain::CurrentDomain->BaseDirectory, _folder, _name + i + _ext), true);
				}
				catch (FileNotFoundException^ ) { }

			}

			FileInfo^ firstFile = gcnew FileInfo(AppDomain::CurrentDomain->BaseDirectory + _name + _ext);
			firstFile->CopyTo(AppDomain::CurrentDomain->BaseDirectory + _name + "2" + _ext, true);
		}



	};
}