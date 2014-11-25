#pragma once

namespace std {

	class __funapi Context : boost::noncopyable
	{
	public:
		virtual void runContext() = 0;
		
		Context();
		virtual ~Context();
	};
	typedef std::weak_ptr<Context> ContextWtr;
	typedef std::shared_ptr<Context> ContextPtr;

}
