#pragma once

namespace std {

	class IService : noncopyable
	{
	public:
	#ifdef __CONSOLE__
		virtual StringWriterPtr runCommand(list<string>& nCommand);
	#endif
		virtual bool runPreinit();
		virtual void runLuaApi();
		
		IService();
		virtual ~IService();
	};
	
}
