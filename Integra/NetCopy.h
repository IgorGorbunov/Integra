#pragma once

namespace Integra {

	using namespace System;
	using namespace System::IO;
	using namespace System::Diagnostics;

	public ref class NetCopy abstract sealed
	{
	private:
		static String^ _share1 = "\\\\192.168.1.1\\Temp\\_models";
		static String^ _share2 = "\\\\192.168.1.192\\share(RW)";
		static String^ _comp1 = "\\\\192.168.1.192\\d$\\temp";
		static String^ _comp2 = "\\\\192.168.1.192\\d$\\temp";
		static String^ _userName = "igor";
		static String^ _password = "igor1983";

	public:
		static Void CopyToMe(String^ filePath)
		{
			CopyFile(filePath, _share1, _userName, _password);
			CopyFile(filePath, _share2, _userName, _password);
			CopyFile(filePath, _comp1, _userName, _password);
			CopyFile(filePath, _comp2, _userName, _password);
		}


		static Void CopyFile(String^ filePath, String^ savePath, String^ userName, String^ password)
		{
			String^ fileName = Path::GetFileName(filePath);
			savePath = Path::Combine(savePath, fileName);
			String^ directory = Path::GetDirectoryName(savePath)->Trim();
			try
			{
				String^ filenameToSave = Path::GetFileName(savePath);

				if (!directory->EndsWith("\\"))
					filenameToSave = "\\" + filenameToSave;

				String^ command = "NET USE " + directory + " /delete";
				ExecuteCommand(command, 5000);

				command = "NET USE " + directory + " /user:" + userName + " " + password;
				ExecuteCommand(command, 1000);

				command = " copy \"" + filePath + "\"  \"" + directory + filenameToSave + "\"";
				ExecuteCommand(command, 5000);
			}
			finally
			{
				String^ command = "NET USE " + directory + " /delete";
				ExecuteCommand(command, 5000);
			}
		}

	private: 
		static int ExecuteCommand(String^ command, int timeout)
		{
			ProcessStartInfo^ processInfo;
			Process^ process;
			try
			{
				processInfo = gcnew ProcessStartInfo("cmd.exe", "/C " + command);
				processInfo->CreateNoWindow = true;
				processInfo->UseShellExecute = false;
				processInfo->WorkingDirectory = "C:\\";

				process = Process::Start(processInfo);
				process->WaitForExit(timeout);
				int exitCode = process->ExitCode;
				process->Close();
				return exitCode;
			}
			catch(InvalidOperationException^ e)
			{
				//сетевой вход не удался
				process->Close();
				delete process;
				return 0;
			}
		} 
	};
}