#pragma once

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

#include "common/definc.h"
#include "common/typeinc.h"
#include "common/error_.h"
#include "common/stdinc.h"
#include "common/libinc.h"
#include "common/default.h"
#include "common/singleton.h"
#include "common/noncopyable.h"
#include "common/convert.h"
#include "common/classid.h"
#include "common/versionid.h"

#include "core/CommandArgs.h"
#include "core/IService.h"
#include "core/InitService.h"
#include "core/Service.h"
