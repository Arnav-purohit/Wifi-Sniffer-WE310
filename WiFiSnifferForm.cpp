#include "WiFiSnifferForm.h"
#include "windows.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Diagnostics;
using namespace System::ComponentModel;

[STAThreadAttribute]
void Main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    WiFiSniffer::WiFiSnifferForm form;
    Application::Run(%form);
}
