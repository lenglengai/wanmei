#include "../DefInc.h"

#include "ITourist.h"

#ifdef __NET__
namespace std {

	ITourist::ITourist(SessionPtr& nSession)
		: mSession (nSession)
	{

	}

	ITourist::~ITourist()
	{

	}

}
#endif
