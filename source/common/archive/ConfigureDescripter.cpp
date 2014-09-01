#include "../DefInc.h"
#include "ConfigureDescripter.h"

#ifdef __ARCHIVE__
namespace std {

	const char * ConfigureDescripter::streamName()
	{
		return "ConfigureDescripter";
	}

	const char * ConfigureDescripter::streamUrl()
	{
		return mStreamUrl.c_str();
	}

	std::list<std::string>& ConfigureDescripter::getConfigures()
	{
		return mConfigures;
	}

	ConfigureDescripter::ConfigureDescripter(const char * nStreamUrl)
		: mStreamUrl(nStreamUrl)
	{
		mConfigures.clear();
	}

	ConfigureDescripter::~ConfigureDescripter()
	{
		mConfigures.clear();
		mStreamUrl = "";
	}

}
#endif
