#pragma once

#ifdef __SETTING__
namespace std {

	class __funapi SettingService : boost::noncopyable
	{
	public:
		void runPreinit(const char * nPath);
		const std::string& systemPath();

	#ifdef __SERVER__
		__i32 checkVersion(__i32 nVersion);
		__i32 checkServerId(__i32 nServerId);
		void setServerId(__i16 nServerId);
		__i16 getServerId();
	#endif

		SettingService();
		~SettingService();

	private:
		std::string mSystemPath;
	#ifdef __SERVER__
		__i16 mServerId;
	#endif
	};

}
#endif
