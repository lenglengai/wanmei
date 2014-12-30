#include "../Include.h"

#ifdef __CONSOLE__
namespace std {
	
	const list<string>& CommandBat::getCommands() const
	{
		return mCommands;
	}
	
	void CommandBat::setStreamName(const char * nStreamName)
	{
		mStreamName = nStreamName;
	}
	
	const char * CommandBat::streamName() const
	{
		return mStreamName.c_str();
	}
	
	const char * CommandBat::streamUrl() const
	{
		return "commandBat";
	}
	
	CommandBat::CommandBat()
		: mStreamName ("commadBat.xml")
	{
	}
	
	CommandBat::~CommandBat()
	{
		mStreamName = "";
	}
	
}
#endif
