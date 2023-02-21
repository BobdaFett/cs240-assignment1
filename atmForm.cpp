#include "atmForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace CS240Assignment1;

[STAThread]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::Run(gcnew atmForm());
	return 0;
}