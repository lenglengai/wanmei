#pragma once

#include "xmlReader.h"

namespace std {

	class SettingService : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize);
		const char * streamName();
		const char * streamUrl();
		__i32 checkServerId(__i32 nServerId);
		void setServerId(__i16 nServerId);
		__i16 getServerId();
		void setServerCount(__i16 nServerCount);
		__i16 getServerCount();
		__i32 checkVersion(__i32 nVersion);
		bool multiThread();
		void runPreinit(const string& nPath);
		void ruLoad();
		template<class T>
		void initUrlStream(T * nUrlStream);
		const string& systemPath();
		SettingService();
		~SettingService();

	private:
		string mSystemPath;
		__i16 mServerCount;
		__i16 mServerId;
		bool mThread;
		__i16 mLower;
		__i32 mHigh;
	};

	template<class T>
	void SettingService::headSerialize(T& nSerialize)
	{
		nSerialize.runInt16(mServerCount, "serverCount");
		nSerialize.runInt16(mServerId, "serverId");
		nSerialize.runInt16(mLower, "lower");
		nSerialize.runInt32(mHigh, "high");
		nSerialize.runBool(mThread, "thread");
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
