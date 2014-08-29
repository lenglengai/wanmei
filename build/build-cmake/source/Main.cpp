#include "../../../source/common/DefInc.h"
#include "../../../source/common/init/InitService.h"

using namespace std;

int main( int argc, char * argv[] )
{
	InitService& initService =
	Singleton<InitService>::instance();
	initService.runPreinit("");
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
	return 0;
}
