#pragma once

#include "xmlReader.h"

namespace std {

	class __funapi SettingService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize);
		const char * streamName();
		const char * streamUrl();

	#if (defined __SERVER__) || (defined __LOGIN__)
		__i32 checkServerId(__i32 nServerId);
		void setServerId(__i16 nServerId);
		__i16 getServerId();
		void setServerCount(__i16 nServerCount);
		__i16 getServerCount();
	#endif
		__i32 checkVersion(__i32 nVersion);
		void runPreinit(const std::string& nPath);
		void ruLoad();
		template<class T>
		void initUrlStream(T * nUrlStream);
		const std::string& systemPath();
		SettingService();
		~SettingService();

	private:
		std::string mSystemPath;
	#if (defined __SERVER__) || (defined __LOGIN__)
		__i16 mServerCount;
		__i16 mServerId;
	#endif
		__i16 mLower;
		__i32 mHigh;
	};

	template<class T>
	void SettingService::headSerialize(T& nSerialize)
	{
	#if (defined __SERVER__) || (defined __LOGIN__)
		nSerialize.runInt16(mServerCount, "serverCount");
		nSerialize.runInt16(mServerId, "serverId");
	#endif
		nSerialize.runInt16(mLower, "lower");
		nSerialize.runInt32(mHigh, "high");
	}

	template<class T>
	void SettingService::initUrlStream(T * nUrlStream)
	{
		XmlReader xmlReader_;
		xmlReader_.openUrl(nUrlStream->streamUrl());
		xmlReader_.selectStream(nUrlStream->streamName());
		nUrlStream->headSerialize(xmlReader_);
		xmlReader_.runClose();
	}

}
