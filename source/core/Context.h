#pragma once

namespace std {

	class __funapi Context : noncopyable
	{
	public:
		virtual void runContext() = 0;
		
		Context();
		virtual ~Context();
	};
	typedef weak_ptr<Context> ContextWtr;
	typedef shared_ptr<Context> ContextPtr;

}
