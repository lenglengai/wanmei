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
		#ifdef __SEVRECV__
			nSerialize.runInt16(mServerCount, "serverCount");
			nSerialize.runInt16(mServerId, "serverId");
		#endif
			nSerialize.runInt16(mLower, "lower");
			nSerialize.runInt32(mHigh, "high");
		}
		const char * streamName();
		const char * streamUrl();
		template<class T>
		void initUrlStream(T * nUrlStream)
		{
			XmlReader xmlReader_;
			xmlReader_.openUrl(nUrlStream->streamUrl());
			xmlReader_.selectStream(nUrlStream->streamName());
			nUrlStream->headSerialize(xmlReader_);
			xmlReader_.runClose();
		}
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
		__i16 mLower;
		__i32 mHigh;
	#ifdef __SEVRECV__
		__i16 mServerCount;
		__i16 mServerId;
	#endif
	};

}
#endif
