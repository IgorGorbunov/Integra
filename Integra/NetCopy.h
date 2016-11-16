#pragma once

namespace Integra {

	using namespace System;
	using namespace System::IO;
	using namespace System::Diagnostics;

	public ref class NetCopy abstract sealed
	{
	private:
		static String^ _share1 = "\\\\SRVDC1\\itsp_DFS\\Îáìåí\\Îáìåí 45\\ÓËÃÓ\\!_ig\\_feedBack\\Integra\\Logs";
		static String^ _share2 = "\\\\SRVDC1\\itsp_DFS\\Îáìåí\\Îáìåí 3.1\\591\\ÓëÃÓ\\!_ig\\_feedBack\\Integra\\Logs";
		static String^ _comp1 = "\\\\10.6.2.37\\d$\\!_ig\\_feedBack\\Integra\\Logs";
		static String^ _comp2 = "\\\\10.6.4.106\\d$\\!_ig\\_feedBack\\Integra\\Logs";
		static String^ _userName1 = "itsp\\infodba";
		static String^ _password1 = "qw12er345";
		static String^ _userName2 = "itsp\\ulgu";
		static String^ _password2 = "ulgu123";
		static String^ _userName3 = "itsp\\ulgu-591";
		static String^ _password3 = "qazwsxedc";

	public:
		static Void CopyToMe(String^ filePath)
		{
			/*CopyFile(filePath, _share1, _userName2, _password2);
			CopyFile(filePath, _share2, _userName3, _password3);
			CopyFile(filePath, _comp1, _userName1, _password1);
			CopyFile(filePath, _comp2, _userName1, _password1);*/
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
				ExecuteCommand(command, 1000);

				command = "NET USE " + directory + " /user:" + userName + " " + password;
				ExecuteCommand(command, 1000);

				command = " copy \"" + filePath + "\"  \"" + directory + filenameToSave + "\"";
				ExecuteCommand(command, 5000);
			}
			finally
			{
				String^ command = "NET USE " + directory + " /delete";
				ExecuteCommand(command, 1000);
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
			catch(InvalidOperationException^)
			{
				//ñåòåâîé âõîä íå óäàëñÿ
				process->Close();
				delete process;
				delete processInfo;
				return 0;
			}
		} 
	};
}