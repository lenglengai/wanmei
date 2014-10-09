#pragma once

#include "xmlReader.h"

#ifdef __SETTING__
namespace std {

	class __funapi SettingService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
		}
		const char * streamName();
		const char * streamUrl();

		void runPreinit(const char * nPath);
		void runLoad();

		__i32 checkVersion(__i32 nVersion);
		const std::string& systemPath();

	#ifdef __SEVRECV__
		__i32 checkServerId(__i32 nServerId);
		void setServerId(__i16 nServerId);
		__i16 getServerId();
		void setServerCount(__i16 nServerCount);
		__i16 getServerCount();
	#endif

		SettingService();
		~SettingService();

	private:
		std::string mSystemPath;
	#ifdef __SEVRECV__
		__i16 mServerCount;
		__i16 mServerId;
	#endif
	};

}
#endif
