#pragma once

namespace std {

	class Context
	{
	public:
		virtual void runContext();
	};
	typedef std::weak_ptr<Context> ContextWtr;
	typedef std::shared_ptr<Context> ContextPtr;

}
