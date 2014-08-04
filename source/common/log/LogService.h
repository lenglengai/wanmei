#pragma once

#include "../DefInc.h"

#ifdef __COCOSLOG__
#define COCOSLOG
#endif

#ifndef COCOSLOG
#include <boost/log/sources/logger.hpp>
#include <boost/format.hpp>

#define log_1(y) boost::format("[%1%]%2%") % __FUN__ % y
#define log_2(y, y0) boost::format("[%1%][%2%]%3%") % __FUN__ % y % y0
#define log_3(y, y0, y1) boost::format("[%1%][%2%][%3%]%4%") % __FUN__ % y % y0 % y1
#define log_4(y, y0, y1, y2) boost::format("[%1%][%2%][%3%][%4%]%5%") % __FUN__ % y % y0 % y1 % y2
#define log_5(y, y0, y1, y2, y3) boost::format("[%1%][%2%][%3%][%4%][%5%]%6%")  % __FUN__ % y % y0 % y1 % y2 % y3
#define log_6(y, y0, y1, y2, y3, y4) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%]%7%")  % __FUN__ % y % y0 % y1 % y2 % y3 % y4
#define log_7(y, y0, y1, y2, y3, y4, y5) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%][%7%]%8%")  % __FUN__ % y % y0 % y1 % y2 % y3 % y4 % y5
#define log_8(y, y0, y1, y2, y3, y4, y5, y6) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%][%7%][%8%]%9%")   % __FUN__ % y % y0 % y1 % y2 % y3 % y4 % y5 % y6
#define log_9(y, y0, y1, y2, y3, y4, y5, y6, y7) boost::format("[%1%][%2%][%3%][%4%][%5%][%6%][%7%][%8%][%9%]%10%")  % __FUN__ % y % y0 % y1 % y2 % y3 % y4 % y5 % y6 % y7
#else
#include <cocos2d.h>

#define log_1(y) y
#define log_2(y, y0) y, y0
#define log_3(y, y0, y1) y, y0, y1
#define log_4(y, y0, y1, y2) y, y0, y1, y2
#define log_5(y, y0, y1, y2, y3) y, y0, y1, y2, y3
#define log_6(y, y0, y1, y2, y3, y4) y, y0, y1, y2, y3, y4
#define log_7(y, y0, y1, y2, y3, y4, y5) y, y0, y1, y2, y3, y4, y5
#define log_8(y, y0, y1, y2, y3, y4, y5, y6) y, y0, y1, y2, y3, y4, y5, y6
#define log_9(y, y0, y1, y2, y3, y4, y5, y6, y7) y, y0, y1, y2, y3, y4, y5, y6, y7
#endif

namespace std {

	#ifndef COCOSLOG
	namespace src = boost::log::sources;
	#endif
	class LogService : boost::noncopyable
	{
	public:
		#ifndef COCOSLOG
		void logError(boost::format& nFormat);
		void logInfo(boost::format& nFormat);
		#else
		template<typename... A>
		void logError(const char * nFormat, A... nArgs)
		{
			CCLOGERROR(nFormat, nArgs...);
		}
		template<typename... A>
		void logInfo(const char * nFormat, A... nArgs)
		{
			CCLOGINFO(nFormat, nArgs...);
		}
		#endif
		void runPreinit();

		LogService();
		~LogService();

	#ifndef COCOSLOG
	private:
		src::logger mLogger;
	#endif
	};

}
