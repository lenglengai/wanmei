#pragma once

#ifdef __HANDLE__
namespace std {

	class __funapi Context
	{
	public:
		virtual void runContext();
	};
	typedef std::weak_ptr<Context> ContextWtr;
	typedef std::shared_ptr<Context> ContextPtr;

}
#endif
