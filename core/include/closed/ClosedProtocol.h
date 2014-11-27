#pragma once

namespace std {

	class ClosedProtocol : public IProtocol
	{
	public:
		bool runPreinit();
		void runInit();

		ClosedProtocol();
		~ClosedProtocol();
	};

}
