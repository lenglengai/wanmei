#pragma once

#include "CommandArgs.h"

namespace std {

	class IService : noncopyable
	{
	#ifdef __CONSOLE__
	public:
		const StringWriterPtr runCommand(const CommandArgs& nCommandArgs);
	protected:
		typedef function<const StringWriterPtr (const CommandArgs&)> CommandRunPtr;
		void registerCommand(const char * nFlags, const CommandRunPtr& nCommandRun);
	private:
		map<string, CommandRunPtr> mCommandRuns;
	#endif
	
	public:
		virtual bool runPreinit();
		
		virtual void runLuaApi();
		virtual bool runConfig();
		virtual bool runInitDb();
		virtual bool runInitTable();
		
		virtual bool loadBegin();
		virtual bool loading();
		virtual bool loadEnd();
		
		virtual bool initBegin();
		virtual bool initing();
		virtual bool initEnd();
		
		virtual void startBegin();
		virtual void starting();
		virtual void startEnd();
		
		virtual void runing();
		
		virtual void stopBegin();
		virtual void stoping();
		virtual void stopEnd();
		
		virtual void runClear();
		
		virtual void resumeBegin();
		virtual void resuming();
		virtual void resumeEnd();
		
		virtual void pauseBegin();
		virtual void pausing();
		virtual void pauseEnd();
		
		virtual bool isPause() const;
		
		IService();
		virtual ~IService();
	};
	
}
