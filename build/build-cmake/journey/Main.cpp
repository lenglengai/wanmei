#include "../../../source/Include.h"

using namespace std;

int main( int argc, char * argv[] )
{
	SettingService& settingService = Singleton<SettingService>::instance();

	settingService.runPreinit(argv[1]);
 	JourneyDescripter journeyDescripter;
 	settingService.initUrlStream(&journeyDescripter);

	settingService.runPreinit("");
	__i32 journeyId = journeyDescripter.getJourneyId();
	std::string journey = "journey_";
	journey += __convert<std::string, __i32>(journeyId);
	journey += ".jf";

	ArchiveWriter archiveWriter;
	archiveWriter.openUrl(journey.c_str());
	std::list<std::string>& journeys = journeyDescripter.getJourneys();
 	archiveWriter.runArchives(journeys);
	archiveWriter.runClose();
	
	return 0;
}
