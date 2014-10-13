#include "../Common.h"

#ifdef __NET__
namespace std {

	Player::Player(SessionPtr& nSession)
		: mSession (nSession)
	{

	}

	Player::~Player()
	{

	}

}
#endif
