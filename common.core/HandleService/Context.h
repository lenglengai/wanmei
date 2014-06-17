#pragma once

namespace std {

	class Context
	{
	public:
		void runContext();
	};
	typedef boost::shared_ptr<Context> ContextPtr;

}
