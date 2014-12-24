#pragma once

namespace std {

	class IService : noncopyable
	{
	public:
	#ifdef __CONSOLE__
		const StringWriterPtr runCommand(const CommandArgs& nCommandArgs);
	#endif
	
	protected:
	#ifdef __CONSOLE__
		typedef function<const StringWriterPtr (const CommandArgs&)> CommandRunPtr;
		void registerCommand(const char * nFlags, const CommandRunPtr& nCommandRun);
	#endif
		virtual void runClear();
	
	public:
		IService();
		virtual ~IService();
		
	private:
	#ifdef __CONSOLE__
		map<string, CommandRunPtr> mCommandRuns;
	#endif
	};
	
}
