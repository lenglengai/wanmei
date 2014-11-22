#include "../include/Include.h"

using namespace std;

int main( int argc, char * argv[] )
{
	InitService& initService = Singleton<InitService>::instance();
	if (argc > 1 && "configure" == argv[1]) {
		initService.runPreinit(true);
		initService.runConfigure();
	} else {
		if (!initService.runPreinit("")) return 0;
		initService.runLoad0();
		initService.runLoad1();
		initService.runInit0();
		initService.runInit1();
		initService.runStart0();
		initService.runStart1();
		initService.runRun();
		initService.runStop();
		initService.runSave();
		initService.runExit();
	}
	return 0;
}
