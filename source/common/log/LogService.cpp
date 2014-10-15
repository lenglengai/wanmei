#include "../Common.h"

#ifdef __BOOSTLOG__

#ifdef __WINDOW__
#pragma warning( push )
#pragma warning( disable : 4819 )
#endif

#include <boost/log/sinks.hpp>
#include <boost/log/common.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/smart_ptr.hpp>

#ifdef __WINDOW__
#pragma warning( pop )
#endif

#endif

#ifdef __LOG__
namespace std {

#ifdef __BOOSTLOG__
	namespace logging = boost::log;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	namespace expr = boost::log::expressions;
	namespace attrs = boost::log::attributes;
#endif

	void LogService::luaLogError(const char * nValue)
	{
#ifdef __BOOSTLOG__
		BOOST_LOG(mLogger) << "[error]" << nValue;
#endif
#ifdef __COCOSLOG__
		CCLOGERROR(nValue);
#endif
	}

	void LogService::luaLogInfo(const char * nValue)
	{
#ifdef __BOOSTLOG__
		BOOST_LOG(mLogger) << "[info]" << nValue;
#endif
#ifdef __COCOSLOG__
		CCLOGINFO(nValue);
#endif
	}

	void LogService::logError(boost::format& nFormat)
	{
#ifdef __BOOSTLOG__
		BOOST_LOG(mLogger) << "[error]" << nFormat;
#endif
#ifdef __COCOSLOG__
		CCLOGERROR(nFormat.str().c_str());
#endif
	}

	void LogService::logInfo(boost::format& nFormat)
	{
#ifdef __BOOSTLOG__
		BOOST_LOG(mLogger) << "[info]" << nFormat;
#endif
#ifdef __COCOSLOG__
		CCLOGINFO(nFormat.str()c_str());
#endif
	}

	void LogService::runScript()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("LogService run runScript!"));
		
		LuaService& luaService_ = Singleton<LuaService>::instance();
		luaService_.runClass<LogService>("LogService");
		luaService_.runMethod<LogService>(&LogService::luaLogError, "logError");
		luaService_.runMethod<LogService>(&LogService::luaLogInfo, "logInfo");
		
		logService_.logInfo(log_1("LogService run runScript finish!"));
	}

	bool LogService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&LogService::runInit, this));

#ifdef __BOOSTLOG__
		auto console_sink = logging::add_console_log();
		console_sink->set_formatter
        (
            expr::format("[%1%]%2%")
                % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
                % expr::smessage
        );
        logging::core::get()->add_sink(console_sink);
		typedef sinks::asynchronous_sink< sinks::text_file_backend > text_sink;
		boost::shared_ptr< text_sink > testSink(new text_sink(keywords::file_name = "%y-%m-%d-%H-%M.log",
			keywords::rotation_size = 10 * 1024 * 1024,
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0)
			));
		testSink->set_formatter
        (
            expr::format("[%1%]%2%")
                % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
                % expr::smessage
        );
    	logging::core::get()->add_sink(testSink);
		logging::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());
#endif
		return true;
	}

	void LogService::runInit()
	{
		this->logInfo(log_1("LogService run runInit!"));
		
		LogService::runScript();
		
		this->logInfo(log_1("LogService run runInit finish!"));
	}

	LogService::LogService()
	{
	}

	LogService::~LogService()
	{
	}

}
#endif
