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

#include "shiny/Shiny.h"

#include "log/LogService.h"
#include "cpu/CpuService.h"
#include "crc/CrcService.h"
#include "random/RandomService.h"
#include "time/TimeService.h"

#include "property/Property.h"
#include "property/IPropertyId.h"
#include "property/PropertyId.h"
#include "property/PropertyMgr.h"
#include "property/PropertySink.h"

#include "closed/Closed.h"
#include "closed/ClosedMgr.h"
#include "closed/ClosedModule.h"
#include "closed/ClosedService.h"
#include "closed/ValueList.h"
#include "closed/IDoing.h"
#include "closed/DoingService.h"
