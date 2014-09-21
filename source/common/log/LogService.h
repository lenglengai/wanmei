#pragma once

#include <boost/format.hpp>

#ifdef __COCOSLOG__
#include <cocos2d.h>
#endif
#ifdef __BOOSTLOG__
#include <boost/log/sources/logger.hpp>
#endif

#define log_1(y) boost::format("[%1%]%2%") % __FUN__ % y
#define log_2(y, y0) boost::format("[%1%][%2%]%3%") % __FUN__ % y % y0
#define log_3(y, y0, y1) boost::format("[%1%][%2%][%3%]%4%") % __FUN__ % y % y0 % y1
#define log_4(y, y0, y1, y2) boost::format("[%1%][%2%][%3%][%4%]%5%") % __FUN__ % y % y0 % y1 % y2
#define log_5(y, y0, y1, y2, y3) boost::format("[%1%][%2%][%3%][%4%][%5%]%6%")  % __FUN__ % y % y0 % y1 % y2 % y3
#define log_6(y, y0, y1, y2, y3, y4) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%]%7%")  % __FUN__ % y % y0 % y1 % y2 % y3 % y4
#define log_7(y, y0, y1, y2, y3, y4, y5) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%][%7%]%8%")  % __FUN__ % y % y0 % y1 % y2 % y3 % y4 % y5
#define log_8(y, y0, y1, y2, y3, y4, y5, y6) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%][%7%][%8%]%9%")   % __FUN__ % y % y0 % y1 % y2 % y3 % y4 % y5 % y6
#define log_9(y, y0, y1, y2, y3, y4, y5, y6, y7) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%][%7%][%8%][%9%]%10%")  % __FUN__ % y % y0 % y1 % y2 % y3 % y4 % y5 % y6 % y7

#ifdef __LOG__
namespace std {

	#ifdef __BOOSTLOG__
	namespace src = boost::log::sources;
	#endif
	class __funapi LogService : boost::noncopyable
	{
	public:
		void logLuaError(const char * nValue);
		void logLuaInfo(const char * nValue);
		void logError(boost::format& nFormat);
		void logInfo(boost::format& nFormat);

		static void runScript();
		void runPreinit();
		void runInit();

		LogService();
		~LogService();
	
	private:
	#ifdef __BOOSTLOG__
		src::logger mLogger;xxxxxxxx
	#endif
	};

}
#endif
