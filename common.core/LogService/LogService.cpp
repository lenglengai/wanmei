#include "../DefInc.h"
#include "LogService.h"



namespace std {

	namespace logging = boost::log;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	namespace expr = boost::log::expressions;
	namespace attrs = boost::log::attributes;
	
	void LogService::logError(boost::format& nFormat)
	{
		BOOST_LOG(mLogger) << nFormat;
	}

	void LogService::runPreinit()
	{
#ifdef _DEBUG
		typedef sinks::asynchronous_sink< sinks::debug_output_backend > debug_sink;
		boost::shared_ptr< debug_sink > debugSink(new debug_sink);
		logging::core::get()->add_sink(debugSink);
#else
		typedef sinks::asynchronous_sink< sinks::text_file_backend > text_sink;
		boost::shared_ptr< text_sink > testSink(new text_sink(keywords::file_name = "%y-%m-%d-%H-%M.log",
			keywords::rotation_size = 10 * 1024 * 1024,
			keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0)
			));
		logging::core::get()->add_sink(testSink);
#endif
	}

	LogService::LogService()
	{
	}

	LogService::~LogService()
	{
	}

}
