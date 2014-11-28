#include "../include/Include.h"

using namespace std;

int main( int argc, char * argv[] )
{
	InitService& initService = Singleton<InitService>::instance();
	if ( (argc > 1) && (std::string("-c") == argv[1]) ) {
		initService.runPreinit(true);
		initService.runConfigure();
	} else if ( (argc > 1) && (std::string("-j") == argv[1]) ) {
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.formatJourney(argv[2], argv[3]);
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
