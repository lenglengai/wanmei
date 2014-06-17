#include "../commmon.core/Include.h"

int main(int argc, char * argv[])
{
	InitService& initService = 
		Singleton<InitService>::instance();
	initService.runPreinit("");
	initService.runLoad();
	initService.runInit();
	initService.runStart();
	initService.runRun();
	initService.runStop();
	initService.runSave();
	initService.runExit();
	return 0;
}
