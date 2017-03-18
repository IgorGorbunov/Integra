
#include "LoginForm.h"
#include "AutoIntegrationManager.h"

using namespace Integra; //name of your project
 
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
 
	//main module

    Application::Run(gcnew LoginForm());

	//autoIntegrationManager

	//release
	//args = gcnew array<System::String ^>(1);
	//args[0] = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=D:\\_Test.accdb;Uid=Admin;Pwd=;";

	//AutoIntegrationManager^ manager = gcnew AutoIntegrationManager(args);
	//manager->StartService();

    return 0;
}