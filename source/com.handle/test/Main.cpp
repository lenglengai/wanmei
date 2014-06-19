#include "../../com.common/DefInc.h"
#include "../Context.h"
#include "../Handle.h"
#include "../HandleService.h"

#include <iostream>

class MyClass : public std::Context
{
public:
	void runContext()
	{
		std::cout << "hello MyClass!" << std::endl;
	}
};

int main( int argc, char * argv[] )
{
	HandleService handleService;
	handleService.runPreinit();
	handleService.runInit();
	handleService.runStart();
	return 0;
}
