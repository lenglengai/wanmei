#include "../../DefInc.h"
#include "../../Common/Convert.h"
#include "../XmlReader.h"
#include "../SettingService.h"

int main( int argc, char * argv[] )
{
    std::SettingService settingService;
    settingService.runPreinit("");
    std::cout << settingService.getServerId() << std::endl;
    std::cout << settingService.getServerCount() << std::endl;
    std::cout << settingService.multiThread() << std::endl;
    return 0;
}
