
#include "LoginForm.h"

using namespace Integra; //name of your project
 
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
 
    Application::Run(gcnew LoginForm());
    return 0;
}