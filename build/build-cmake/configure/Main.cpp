#include "../../../source/common/DefInc.h"
#include "../../../source/common/setting/SettingService.h"
#include "../../../source/common/archive/ConfigureDescripter.h"
#include "../../../source/common/archive/ArchiveWriter.h"

using namespace std;

int main( int argc, char * argv[] )
{
	SettingService& settingService =
		Singleton<SettingService>::instance();
	settingService.runPreinit(argv[1]);
 	ConfigureDescripter configureDescripter(argv[2]);
 	settingService.initUrlStream(&configureDescripter);
	settingService.runPreinit("");
 	ArchiveWriter archiveWriter;
 	archiveWriter.runConfigureDescripter(configureDescripter);
	archiveWriter.runClose();
	return 0;
}
