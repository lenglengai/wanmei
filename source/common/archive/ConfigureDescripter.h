#pragma once

#ifdef __ARCHIVE__
namespace std {

	class ConfigureDescripter : boost::noncopyable
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runStrings(mConfigures, "configures", "configure");
		}
		const char * streamName();
		const char * streamUrl();

		std::list<std::string>& getConfigures();

		ConfigureDescripter(const char * nStreamUrl);
		~ConfigureDescripter();

	private:
		std::list<std::string> mConfigures;
		std::string mStreamUrl;
	};


}
#endif
