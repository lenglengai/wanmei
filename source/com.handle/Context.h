#pragma once

namespace std {

	class Context
	{
	public:
		virtual void runContext();
	};
	typedef boost::shared_ptr<Context> ContextPtr;

}
