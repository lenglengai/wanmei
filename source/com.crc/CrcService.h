#pragma once

#include <boost/date_time.hpp>

namespace std {

	class CrcService : boost::noncopyable
	{
	public:
		__i64 runId(const char * nName);
		__i64 runId(__i32 nId);
		__i32 runCommon(const char * nName);
		__i32 runComputer();
		__i32 runCellphone();
		__i32 runName(const char * nName);
		__i32 runPassward(const char * nName);
		__i32 runCluster(const char * nName);
		__i32 runServer(const char * nName);
		__i32 runDatabase(const char * nName);
		__i32 runTable(const char * nName);
		void runPreinit();

		CrcService();
		~CrcService();

	private:
		__i32 hashString(const char * nKey, __i16 nOffset);

	private:
		boost::posix_time::ptime mTime;
	};

}
