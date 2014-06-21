#include "../com.common/DefInc.h"
#include "../com.init/InitService.h"

int main( int argc, char * argv[] )
{
	std::InitService& initService = 
		std::Singleton<std::InitService>::instance();
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
