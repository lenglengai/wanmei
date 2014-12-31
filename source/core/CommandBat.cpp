#include "../Include.h"

#ifdef __CONSOLE__
namespace std {
	
	const list<string>& CommandBat::getCommands() const
	{
		return mCommands;
	}
	
	void CommandBat::setStreamUrl(const char * nStreamUrl)
	{
		mStreamUrl = nStreamUrl;
	}
	
	const char * CommandBat::streamName() const
	{
		return "commandBat";
	}
	
	const char * CommandBat::streamUrl() const
	{
		return mStreamUrl.c_str();
		
	}
	
	CommandBat::CommandBat()
		: mStreamUrl("commadBat.xml")
	{
	}
	
	CommandBat::~CommandBat()
	{
		mStreamUrl = "";
	}
	
}
#endif
