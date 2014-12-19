#include "../Include.h"

namespace std {

	const string& getCommand(__i32 nIndex) const
	{
		if (mArgs.size() > nIndex) {
			return mArgs[nIndex];
		}
		return __default<string>();
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
					mArgs.push_back(command_);
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
		mArgs.clear();
		mService = "";
		mFlags = "";
	}
	
	CommandArgs::CommandArgs(const string& nCommand)
	{
		this->runClear();
		this->runParse(nCommand);
	}
	
	CommandArgs::~CommandArgs()
	{
		this->runClear();
	}
	
}
