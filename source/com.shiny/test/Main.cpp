#include "../Shiny.h"


#include <iostream>


void fun()
{
	PROFILE_FUNC();
	std::cout << "hello world!" << std::endl;
}

int main( int argc, char * argv[] )
{
	for (int i = 0; i < 10; ++i)
	{
		fun();
	}
	PROFILER_UPDATE();
	PROFILER_OUTPUT("profile.txt");
	return 0;
}
