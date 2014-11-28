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

#include "log/LogService.h"
#include "lua/LuaWriter.h"
#include "lua/LuaScript.h"
#include "lua/LuaService.h"
#include "cpu/CpuService.h"
#include "crc/CrcService.h"
#include "random/RandomService.h"
#include "time/TimeService.h"

#include "property/Property.h"
#include "property/IPropertyId.h"
#include "property/PropertyId.h"
#include "property/PropertyMgr.h"
#include "property/PropertySink.h"

#include "compress/CompressService.h"
#include "handle/Context.h"
#include "handle/Handle.h"
#include "handle/HandleService.h"
#include "ioservice/IoService.h"
#include "init/InitType_.h"
#include "init/InitService.h"
#include "setting/SettingService.h"
#include "net/IBlock.h"
#include "net/ReadBlock.h"
#include "net/WriteBlock.h"
#include "value/IValue.h"
#include "value/ValueList.h"
#include "value/Values.h"
#include "net/IPacket.h"
#include "net/Session.h"
#include "net/Robot.h"
#include "net/Player.h"
#include "net/SingleWire.h"
#include "net/PlayerService.h"
#include "net/IProtocol.h"
#include "net/ProtocolService.h"
#include "net/TcpClient.h"
#include "net/TcpServer.h"

#include "archive/IJourney.h"
#include "archive/JourneyKey.h"
#include "archive/JourneyDescripter.h"
#include "archive/XmlReader.h"
#include "archive/LogWriter.h"
#include "archive/BinWriter.h"
#include "archive/BinReader.h"
#include "archive/ArchiveHash.h"
#include "archive/ArchiveHead.h"
#include "archive/Archive.h"
#include "archive/ArchiveReader.h"
#include "archive/ArchiveWriter.h"
#include "archive/ArchiveService.h"

#include "closed/IndexValue.h"
#include "closed/Closed.h"
#include "closed/Closeds.h"
#include "closed/ClosedMgr.h"
#include "closed/ClosedModule.h"
#include "closed/ClosedService.h"
#include "closed/IDoing.h"
#include "closed/DoingService.h"
#include "closed/C2SClosed.h"
#include "closed/S2CClosed.h"
#include "closed/ClosedProtocol.h"
