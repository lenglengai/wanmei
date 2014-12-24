#pragma once

#ifdef __BOOSTLOG__
#include <boost/log/sources/logger.hpp>
#endif

#ifdef __COCOSLOG__
#include <cocos2d.h>
#endif

#define log_0() boost::format("[%1%:%2%]") % __FUN__ % __LINE__
#define log_1(y) boost::format("[%1%:%2%]%3%") % __FUN__ % __LINE__ % y
#define log_2(y, y0) boost::format("[%1%:%2%]%3%:%4%") % __FUN__ % __LINE__ % y % y0
#define log_3(y, y0, y1) boost::format("[%1%:%2%]%3%:%4%:%5%") % __FUN__ % __LINE__ % y % y0 % y1
#define log_4(y, y0, y1, y2) boost::format("[%1%:%2%]%3%:%4%:%5%:%6%") % __FUN__ % __LINE__ % y % y0 % y1 % y2
#define log_5(y, y0, y1, y2, y3) boost::format("[%1%:%2%]%3%:%4%:%5%:%6%:%7%")  % __FUN__ % __LINE__ % y % y0 % y1 % y2 % y3
#define log_6(y, y0, y1, y2, y3, y4) boost::format("[%1%:%2%]%3%:%4%:%5%:%6%:%7%:%8%")  % __FUN__ % __LINE__ % y % y0 % y1 % y2 % y3 % y4
#define log_7(y, y0, y1, y2, y3, y4, y5) boost::format("[%1%:%2%]%3%:%4%:%5%:%6%:%7%:%8%:%9%")  % __FUN__ % __LINE__% y % y0 % y1 % y2 % y3 % y4 % y5
#define log_8(y, y0, y1, y2, y3, y4, y5, y6) boost::format("[%1%:%2%]%3%:%4%:%5%:%6%:%7%:%8%:%9%:%10%")   % __FUN__ % __LINE__ % y % y0 % y1 % y2 % y3 % y4 % y5 % y6
#define log_9(y, y0, y1, y2, y3, y4, y5, y6, y7) boost::format("[%1%:%2%]%3%:%4%:%5%:%6%:%7%:%8%:%9%:%10%:%11%")  % __FUN__ % __LINE__ % y % y0 % y1 % y2 % y3 % y4 % y5 % y6 % y7

namespace std {

#ifdef __BOOSTLOG__
	namespace src = boost::log::sources;
#endif
	class __funapi LogService : public IService
	{
	public:
		static LogService * getLogService();
		void luaError(const char * nValue);
		void luaInfo(const char * nValue);
		
		void logError(boost::format& nFormat);
		void logInfo(boost::format& nFormat);
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandLogError(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandLogInfo(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit();
		void runLuaApi();

		LogService();
		~LogService();
		
#ifdef __BOOSTLOG__
	private:
		src::logger mLogger;
#endif
	};
	
}
