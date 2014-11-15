#pragma once

#include "include/DefInc.h"
#include "include/TypeInc.h"
#include "include/ERRORINT.h"
#include "include/StdInc.h"
#include "include/LibInc.h"
#include "include/Default.h"
#include "include/Singleton.h"
#include "include/Preinit.h"
#include "include/Convert.h"

#include <VerInc.h>
#include <Journey.h>

#ifdef __COCOS2DX__
#include "projInc/CocoClient.h"
#endif

#ifdef __GAMECLIENT__
#include "projInc/GameClient.h"
#endif

#ifdef __GAMESERVER__
#include "projInc/GameServer.h"
#endif

#ifdef __LOGINSERVER__
#include "projInc/LoginServer.h"
#endif
