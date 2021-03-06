#include "../Include.h"

#ifdef __BOOSTLOG__
#include <boost/log/sinks.hpp>
#include <boost/log/common.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/smart_ptr.hpp>
#endif

namespace std {

#ifdef __BOOSTLOG__
	namespace logging = boost::log;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	namespace expr = boost::log::expressions;
	namespace attrs = boost::log::attributes;
#endif

#ifdef __CONSOLE__
	const StringWriterPtr LogService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<LogService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr LogService::commandLogError(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		bool first_ = true; string strCommands_("");
		for (__i32 i = 1; i <= nCommandArgs.getCommandCount(); ++i) {
			if (!first_) {
				strCommands_ += " ";
			} else {
				first_ = false;
			}
			strCommands_ += nCommandArgs.getCommandArg(i);
		}
		this->logError(log_1(strCommands_));
		stringWriter_->runString(strCommands_, "strCommands");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr LogService::commandLogInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		bool first_ = true; string strCommands_("");
		for (__i32 i = 1; i <= nCommandArgs.getCommandCount(); ++i) {
			if (!first_) {
				strCommands_ += " ";
			} else {
				first_ = false;
			}
			strCommands_ += nCommandArgs.getCommandArg(i);
		}
		this->logInfo(log_1(strCommands_));
		stringWriter_->runString(strCommands_, "strCommands");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
	
	void LogService::luaError(const char * nValue)
	{
#ifdef __BOOSTLOG__
		BOOST_LOG(mLogger) << "[error]" << nValue;
#endif
#ifdef __COCOSLOG__
		CCLOGERROR(nValue);
#endif
	}

	void LogService::luaInfo(const char * nValue)
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

	LogService * LogService::getLogService()
	{
		LogService& logService_ = Service<LogService>::instance();
		return (&logService_);
	}
	
	bool LogService::runPreinit()
	{		
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&LogService::commandInfo, this, placeholders::_1));
		this->registerCommand("findName", std::bind(&LogService::commandLogError, this, placeholders::_1));
		this->registerCommand("findId", std::bind(&LogService::commandLogInfo, this, placeholders::_1));
	#endif
	
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

		string fileName(APPNAME); fileName += "%Y-%m-%d.log";
		boost::shared_ptr< text_sink > testSink(new text_sink(keywords::file_name = fileName.c_str(),
			keywords::rotation_size = 10 * 1024 * 1024,
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
			keywords::open_mode = (std::ios::out | std::ios::app)
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

	void LogService::runLuaApi()
	{
	#ifdef __EXPLUA__
		LuaService& luaService_ = Service<LuaService>::instance();
		luaService_.runClass<LogService>("LogService");
		luaService_.runFun(&LogService::getLogService, "getLogService");
		luaService_.runMethod<LogService>(&LogService::luaError, "logError");
		luaService_.runMethod<LogService>(&LogService::luaInfo, "logInfo");
	#endif
	}

	LogService::LogService()
	{
	}

	LogService::~LogService()
	{
	}
	
	static Service<LogService> sLogService;

}
