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

#include "core/StringWriter.h"
#include "core/CommandArgs.h"
#include "core/Context.h"
#include "core/Handle.h"
#include "core/IService.h"
#include "core/HandleService.h"
#include "core/LogService.h"
#include "core/ServiceMgr.h"
#include "core/Console.h"
#include "core/Preinit.h"
#include "core/LuaEngine.h"
#include "core/LuaService.h"
#include "core/TimeService.h"
#include "core/CrcService.h"
#include "core/CompressService.h"
#include "core/InitService.h"
#include "core/DebugService.h"
#include "core/RandomService.h"
#include "core/TimeService.h"

#include "core/Property.h"
#include "core/IPropertyId.h"
#include "core/PropertyId.h"
#include "core/PropertyMgr.h"
#include "core/PropertySink.h"

#include "archive/XmlReader.h"
#include "archive/BinWriter.h"
#include "archive/BinReader.h"
#include "archive/ArchiveHash.h"
#include "archive/ArchiveHead.h"
#include "archive/Archive.h"
#include "archive/ArchiveReader.h"
#include "archive/ArchiveWriter.h"
#include "archive/ArchiveService.h"
