#include "SystemClass.h"
#include "d3d10.h"

//#pragma comment(lib, "d3d10.lib")
//#pragma comment(lib, "WinMM.lib")

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow) {
	SystemClass *system;
	bool result;

	system = new SystemClass;
	if (!system) {
		return 0;
	}

	result = system->Initialize();
	if (result) {
		system->Run();
	}

	system->Shutdown();
	delete system;
	system = 0;

	return 0;
}