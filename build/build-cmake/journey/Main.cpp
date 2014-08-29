#include "../../../source/common/DefInc.h"
#include "../../../source/common/setting/SettingService.h"
#include "../../../source/common/archive/JourneyDescripter.h"
#include "../../../source/common/archive/ArchiveWriter.h"

using namespace std;

int main( int argc, char * argv[] )
{
	SettingService& settingService =
		Singleton<SettingService>::instance();
	settingService.runPreinit(argv[1]);
 	JourneyDescripter journeyDescripter;
 	settingService.initUrlStream(&journeyDescripter);
	settingService.runPreinit("");
 	ArchiveWriter archiveWriter;
 	archiveWriter.runJourneyDescripter(journeyDescripter);
	archiveWriter.runClose();
	
	return 0;
}
