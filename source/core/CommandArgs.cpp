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
		if (mCommandArgs.size() > nIndex) {
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
		__i32 i = 0, j = 0; bool space_ = true;
		for (; i < nCommand.length(); ++i) {
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
			} else (1 == j) {
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
