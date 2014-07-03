#include "../../common/DefInc.h"

#include "IPlayer.h"

namespace std {

	IPlayer::IPlayer(SessionPtr& nSession)
		: mSession (nSession)
	{

	}

	IPlayer::~IPlayer()
	{

	}

}
