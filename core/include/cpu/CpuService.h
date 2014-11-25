#pragma once

#ifdef __WITHCPU__
namespace std {
	
	class __funapi CpuService : boost::noncopyable
	{
	public:
		__i16 getCpuCount();
		bool runPreinit();
		
		CpuService();
		~CpuService();
		
	private:
		__i16 mCpuCount;
	};
	
}
#endif
