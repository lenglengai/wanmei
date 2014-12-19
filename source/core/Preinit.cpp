#include "../Include.h"

namespace std {

	void PreinitSlot::pushPreinit0(std::function<bool ()>& nPreinit)
	{
		mPreinit0s.push_back(nPreinit);
	}
	
	void PreinitSlot::pushPreinit1(std::function<bool ()>& nPreinit)
	{
		mPreinit1s.push_back(nPreinit);
	}
	
	bool PreinitSlot::runPreinit0()
	{
		for ( auto& it : mPreinit0s) {
			if (!it()) {
				return false;
			}
		}
		return true;
	}
	
	bool PreinitSlot::runPreinit1()
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
