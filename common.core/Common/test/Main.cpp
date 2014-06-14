#include "../Convert.h"
#include "../Default.h"
#include "../ERRORINT.h"
#include "../Singleton.h"

class MyClass 
{
public:
	void fun()
	{
		std::cout << "MyClass" << std::ERRORINT::HAVEUPDATE << std::endl;
	}
};



int main()
{
	MyClass& myClass = std::Singleton<MyClass>::instance();
	myClass.fun();

	std::cout << "bool" << std::__default<bool>() << std::endl;
	std::cout << "__i8" <<  std::__default<__i8>() << std::endl;
	std::cout << "__i16" <<  std::__default<__i16>() << std::endl;
	std::cout << "__i32" <<  std::__default<__i32>() << std::endl;
	std::cout << "__i64" <<  std::__default<__i64>() << std::endl;
	std::cout << "std::string" <<  std::__default<std::string>() << std::endl;
	std::cout << "float" <<  std::__default<float>() << std::endl;
	std::cout << "double" <<  std::__default<double>() << std::endl;
	std::cout << "char *" <<  std::__default<const char *>() << std::endl;


	std::cout << "//////////////////////////////////__i8///////////////////////////" << std::endl;
	std::cout << "bool" << std::__convert<__i8, bool>(true, std::mConvertTypeCommon_) << std::endl;
	std::cout << "bool" << std::__convert<__i8, bool>(true, std::mConvertTypeText_) << std::endl;
	std::cout << "bool" << std::__convert<__i8, bool>(false, std::mConvertTypeCommon_) << std::endl;
	std::cout << "bool" << std::__convert<__i8, bool>(false, std::mConvertTypeText_) << std::endl;
	std::cout << "__i16" << std::__convert<__i8, __i16>(127, std::mConvertTypeCommon_) << std::endl;
	std::cout << "__i32" << std::__convert<__i8, __i32>(127, std::mConvertTypeCommon_) << std::endl;
	std::cout << "__i64" << std::__convert<__i8, __i64>(127, std::mConvertTypeCommon_) << std::endl;
	std::cout << "float" << std::__convert<__i8, float>(126.f, std::mConvertTypeCommon_) << std::endl;
	std::cout << "double" << std::__convert<__i8, double>(126., std::mConvertTypeCommon_) << std::endl;
	std::cout << "const char *" << std::__convert<__i8, const char *>("21", std::mConvertTypeCommon_) << std::endl;
	std::cout << "//////////////////////////////////__i16///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////__i32///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////__i64///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////__float///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////__double///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////__std::string///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////bool///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////const char *///////////////////////////" << std::endl;
	std::cout << "//////////////////////////////////char *///////////////////////////" << std::endl;

	



	return 0;
}
