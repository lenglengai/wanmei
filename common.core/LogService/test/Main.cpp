#include "../../DefInc.h"
#include "../LogService.h"

class MyClass
{
public:
    void fun()
    {
        std::LogService logService;
        logService.runPreinit();
        logService.logError(log_1("hello world!"));
        std::cin.get();
    }
};

int main( int argc, char * argv[] )
{
    MyClass myClass ;
    myClass.fun();

    return 0;
}
