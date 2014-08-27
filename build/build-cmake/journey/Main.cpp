#include "../../../source/common/DefInc.h"
#include "../../../source/common/setting/SettingService.h"
#include "../../../source/common/archive/JourneyDescripter.h"
#include "../../../source/common/archive/ArchiveWriter.h"

using namespace std;

int main( int argc, char * argv[] )
{
	std::SettingService& settingService =
	std::Singleton<std::SettingService>::instance();
 	settingService.runPreinit(argv[1]);
 	std::JourneyDescripter journeyDescripter;
 	settingService.initUrlStream(&journeyDescripter);
	settingService.runPreinit("");
 	std::ArchiveWriter archiveWriter;
 	archiveWriter.runJourneyDescripter(journeyDescripter);
	archiveWriter.runClose();
	return 0;
}
