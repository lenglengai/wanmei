#include "../../include/Include.h"

namespace std {

	void ValueList::runClear()
	{
		mValues.clear();
	}
	
	ValueList::ValueList()
	{
		this->runClear();
	}
	
	ValueList::~ValueList()
	{
		this->runClear();
	}
	
}
