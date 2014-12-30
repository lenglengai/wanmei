#include "Include.h"

using namespace std;

int main( int argc, char * argv[] )
{
	InitService& initService = Singleton<InitService>::instance();
	if (!initService.runPreinit()) return 0;
	initService.runLoad0();
	initService.runLoad1();
#ifdef __CONSOLE__
	if (argc > 1) {
		initService.runCommand(argv[1]);
	}
#endif
	initService.runInit0();
	initService.runInit1();
	initService.runStart0();
	initService.runStart1();
	initService.runRun();
	initService.runStop1();
	initService.runSave();
	initService.runExit();
	return 0;
}
