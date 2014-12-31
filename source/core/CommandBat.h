#pragma once

#ifdef __CONSOLE__
namespace std {
	
	class CommandBat
	{
	public:
		const list<string>& getCommands() const;
		template<class __t>
		void headSerialize(__t& nT)
		{
			nT.runStrings(mCommands, "commands", "command");
		}
		
		const char * streamName() const;
		
		void setStreamUrl(const char * nStreamUrl);
		const char * streamUrl() const;
		
		CommandBat();
		~CommandBat();
		
	private:
		list<string> mCommands;
		string mStreamUrl;
	};
	
}
#endif
