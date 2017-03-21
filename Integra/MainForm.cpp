
#include "LoginForm.h"
#include "AutoIntegrationManager.h"
#include "AutoIntegrationTemplate.h"
#include "TestExeIntegration.h"

using namespace Integra; //name of your project
 
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
 
	//--- main module

    //Application::Run(gcnew LoginForm());

	//--- autoIntegrationManager.exe

	//release
	//args = gcnew array<System::String ^>(1);
	//args[0] = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=D:\\_Test.accdb;Uid=Admin;Pwd=;";
	//args[0] = "Driver={Microsoft ODBC for Oracle};Server=OTL.KTPP.AVIASTAR.LINK-UL.RU;Uid=ulgu1;Pwd=1;";

	//AutoIntegrationManager^ manager = gcnew AutoIntegrationManager(args);
	//manager->StartService();


	//--- autoIntegrationTemplate.exe

	//release
	//args = gcnew array<System::String ^>(2);
	//args[0] = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=D:\\_Test.accdb;Uid=Admin;Pwd=;";
	//args[0] = "Driver={Microsoft ODBC for Oracle};Server=OTL.KTPP.AVIASTAR.LINK-UL.RU;Uid=ulgu1;Pwd=1;";
    //args[1] = "2";

	//AutoIntegrationTemplate^ templ = gcnew AutoIntegrationTemplate(args);
	//templ->StartIntegration();

	//--- end editCompilation

	//--- AutoIntegrationManager

	//release
	//args = gcnew array<System::String ^>(1);
	//args[0] = "{Атрибут1 [СТРОКА] - фывафыва фываф ыв}, {Атрибут2 [с точкой] - 200,12}, {Атрибут 3 [с точкой] - 200.2}";

	TestExeIntegration^ test = gcnew TestExeIntegration(args);
	test->StartService();

    return 0;
}