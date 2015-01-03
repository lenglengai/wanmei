#include "../Include.h"

namespace std {

	void CommandArgs::runStringWriter(StringWriterPtr& nStringWriter) const
	{
		nStringWriter->startClass("command");
		nStringWriter->runString(mService, "service");
		nStringWriter->runString(mFlags, "flags");
		nStringWriter->runStrings(mCommandArgs, "commandArgs");
		nStringWriter->finishClass();
	}
	
	const string& CommandArgs::getCommandArg(const __i32 nIndex) const
	{
		__i32 commandArgsCount_ = static_cast<__i32>(mCommandArgs.size());
		if (commandArgsCount_ >= nIndex) {
			return mCommandArgs[nIndex - 1];
		}
		return __default<string>();
	}
	
	__i32 CommandArgs::getCommandCount() const
	{
		return mCommandArgs.size();
	}
	
	const string& CommandArgs::getService() const
	{
		return mService;
	}
	
	const string& CommandArgs::getFlags() const
	{
		return mFlags;
	}
	
	void CommandArgs::runParse(const string& nCommand)
	{
		this->runClear();
		string command_("");
		bool space_ = true; __i32 commandType_ = 0;
		__i32 commandLength_ = static_cast<__i32>(nCommand.length());
		for (__i32 i = 0; i < commandLength_; ++i) {
			if (' ' == nCommand[i]) {
				if (space_) {
					continue;
				}
				space_ = true;
				if (commandType_ > 2) {
					mCommandArgs.push_back(command_);
					command_ = "";
				}
				continue;
			}
			if (space_) {
				commandType_++;
				space_ = false;
			}
			if (1 == commandType_) {
				mService.push_back(nCommand[i]);
			} else if (2 == commandType_) {
				mFlags.push_back(nCommand[i]);
			} else {
				command_.push_back(nCommand[i]);
			}
		}
		if ("" != command_) {
			mCommandArgs.push_back(command_);
		}
	}
	
	void CommandArgs::runClear()
	{
		mCommandArgs.clear();
		mService = "";
		mFlags = "";
	}
	
	CommandArgs::CommandArgs()
	{
		this->runClear();
	}
	
	CommandArgs::~CommandArgs()
	{
		this->runClear();
	}
	
}
