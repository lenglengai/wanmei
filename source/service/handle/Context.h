#pragma once

namespace std {

	class Context
	{
	public:
		virtual void runContext();
	};
	typedef boost::weak_ptr<Context> ContextWtr;
	typedef boost::shared_ptr<Context> ContextPtr;

}
