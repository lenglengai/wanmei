#include "../Include.h"

namespace std {

	void CommandArgs::runStringWriter(StringWriterPtr& nStringWriter) const
	{
		nStringWriter->runString(mService, "service");
		nStringWriter->runString(mFlags, "flags");
		nStringWriter->runStrings(mCommandArgs, "commandArgs");
	}
	
	const string& CommandArgs::getCommand(__i32 nIndex) const
	{
		__i32 commandArgsCount_ = static_cast<__i32>(mCommandArgs.size());
		if (commandArgsCount_ > nIndex) {
			return mCommandArgs[nIndex];
		}
		return __default<string>();
	}
	
	const __i32 CommandArgs::getCommandCount() const
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
		bool space_ = true;
		__i32 commandLength_ = static_cast<__i32>(nCommand.length());
		for (__i32 i = 0, j = 0; i < commandLength_; ++i) {
			if (' ' == nCommand[i]) {
				if (space_) {
					continue;
				}
				++j;
				space_ = true;
				if (j > 1) {
					mCommandArgs.push_back(command_);
					command_ = "";
				}
				continue;
			}
			if (space_) {
				space_ = false;
			}
			if ('-' == nCommand[i]) {
				continue;
			}
			if (0 == j) {
				mService.push_back(nCommand[i]);
			} else if (1 == j) {
				mFlags.push_back(nCommand[i]);
			} else {
				command_.push_back(nCommand[i]);
			}
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
