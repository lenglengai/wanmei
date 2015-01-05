#include "../Include.h"

#ifdef __WITHSQL__
namespace std {
	
	void IDbQuery::returnResult(string& nValue)
	{
		this->getValue(nValue);
	}
	
}
#endif
