#include "../../include/Include.h"

namespace std {

	std::map<__i32, ClosedPtr>& Closeds::getCloseds()
	{
		return mCloseds;
	}
	
	Closeds::Closeds()
	{
		mCloseds.clear();
	}
	
	Closeds::~Closeds()
	{
		mCloseds.clear();
	}
	
}
