#pragma once

namespace std {

	class ContextService : boost::noncopyable
	{
	public:
		void pushPacket(__i16 nContextId, PacketPtr& nPacket);
		
		ContextService();
		~ContextService();
		
	private:
		std::map<__i16, ContextPtr> mContexts;
	};
	
}
