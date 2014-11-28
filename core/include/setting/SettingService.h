#pragma once

namespace std {

	class __funapi SettingService : boost::noncopyable
	{
	public:	
		void setSystemPath(const char * nSystemPath);
		const std::string& systemPath();

		__i16 checkVersion(__i16 nVersion);
		__i16 getVersion();
		
		bool runPreinit();
		
		SettingService();
		~SettingService();

	private:
		std::string mSystemPath;
	};

}
