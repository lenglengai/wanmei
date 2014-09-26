#pragma once

#ifdef APIEXPORT
#define __funapi __declspec(dllexport)
#else
#define __funapi
#endif

#ifdef _WIN32
#define __FUN__ __FUNCTION__
#else
#define __FUN__ __PRETTY_FUNCTION__
#endif

#define INITYEAR	2014
#define INITMONTH	9
#define INITDAY		1

#include <boost/noncopyable.hpp>
#include <boost/signals2.hpp>
#include <boost/bind.hpp>

#include <memory>
#include <string>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <vector>

#ifdef __JOURNEY__
#include <JourneyInclude.h>
#endif

#ifdef __ANDROID__
#include <AndroidInclude.h>
#endif

#ifdef __GAMECLIENT__
#include <GameClient.h>
#endif

#ifdef __GAMESERVER__
#include <GameServer.h>
#endif

#ifdef __LOGINSERVER__
#include <LoginServer.h>
#endif

#include "utility/Singleton.h"
#include "utility/Convert.h"
#include "utility/Default.h"
#include "utility/ERRORINT.h"
#include "shiny/Shiny.h"
#include "lua/LuaService.h"
#include "log/LogService.h"
#include "init/InitService.h"

