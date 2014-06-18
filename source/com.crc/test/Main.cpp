#include "../../DefInc.h"
#include "../CrcService.h"


int main( int argc, char * argv[] )
{
	std::CrcService crcService;
	crcService.runPreinit();
	std::cout << crcService.runId("hello") << std::endl;
	std::cout << crcService.runId("2045") << std::endl;
	std::cout << crcService.runCommon("computer") << std::endl;
	std::cout << crcService.runComputer() << std::endl;
	std::cout << crcService.runCellphone() << std::endl;
	std::cout << crcService.runName("cellphone") << std::endl;

	return 0;
}
