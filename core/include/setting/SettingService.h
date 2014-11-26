#pragma once

namespace std {

	class __funapi SettingService : boost::noncopyable
	{
	public:
		bool runPreinit();
		__i16 getVersion();
		const std::string& systemPath();

		__i16 checkVersion(__i16 nVersion);

		SettingService();
		~SettingService();

	private:
		std::string mSystemPath;
	};

}
