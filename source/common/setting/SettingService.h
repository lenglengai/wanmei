#pragma once

namespace std {

	class __funapi SettingService : boost::noncopyable
	{
	public:
		bool runPreinit(const char * nPath);
		const std::string& systemPath();

	#ifdef __SERVER__
		__i32 checkVersion(__i32 nVersion);
	#endif

		SettingService();
		~SettingService();

	private:
		std::string mSystemPath;
	};

}
