#pragma once

namespace std {

	class WireProtocol
	{
	public:
		WireProtocol();
		~WireProtocol();
	};
	typedef std::shared_ptr<WireProtocol> WireProtocolPtr;
	
}
