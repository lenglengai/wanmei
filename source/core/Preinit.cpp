#include "../Include.h"

namespace std {

	void PreinitSlot::pushPreinit0(const function<bool ()>& nPreinit)
	{
		mPreinit0s.push_back(nPreinit);
	}
	
	void PreinitSlot::pushPreinit1(const function<bool ()>& nPreinit)
	{
		mPreinit1s.push_back(nPreinit);
	}
	
	const bool PreinitSlot::runPreinit0() const
	{
		for ( auto& it : mPreinit0s) {
			if (!it()) {
				return false;
			}
		}
		return true;
	}
	
	const bool PreinitSlot::runPreinit1() const
	{
		for ( auto& it : mPreinit1s) {
			if (!it()) {
				return false;
			}
		}
		return true;
	}
	
	void PreinitSlot::runClear()
	{
		mPreinit0s.clear();
		mPreinit1s.clear();
	}
	
	PreinitSlot::PreinitSlot()
	{
		this->runClear();
	}
	
	PreinitSlot::~PreinitSlot()
	{
		this->runClear();
	}
	
}
