#include "../../../source/common/DefInc.h"
#include "../../../source/common/time/TimeService.h"

using namespace std;

int main( int argc, char * argv[] )
{
	TimeService& timeService =
	Singleton<TimeService>::instance();
	timeService.runPreinit();
	return 0;
}
