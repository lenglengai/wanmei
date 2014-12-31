#include "../Include.h"

#ifdef __WITHMYSQL__
namespace std {
	
	void IDbQuery::returnResult(string& nValue)
	{
		this->getValue(nValue);
	}
	
}
#endif
