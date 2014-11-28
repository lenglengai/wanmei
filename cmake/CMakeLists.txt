cmake_minimum_required(VERSION 3.0)

project(${__PROJECT__})

string(TOUPPER ${__PROJECT__} __PROJNAME__)
add_definitions(-D__${__PROJNAME__}__)

if(WIN32)
  add_definitions("-D_WIN32_WINNT=0x0601")
  set(CMAKE_C_FLAGS_DEBUG   "/MDd /Zi /Od /Ob0 /RTC1")
  set(CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Od /Ob0 /RTC1")
  set(CMAKE_C_FLAGS_RELEASE   "/MT /O2 /Ob2 /DNDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /DNDEBUG")
  set(CMAKE_EXE_LINKER_FLAGS "/MANIFEST:NO")
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
else()
  set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

include_directories(../${__WORKSPACE__}/cppInc)

include_directories($ENV{BOOST_ROOT})
link_directories($ENV{BOOST_ROOT}/stage/lib)
set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost COMPONENTS system date_time regex chrono thread filesystem log log_setup REQUIRED)

##############################################################
set( ROOT_PATH ${CMAKE_SOURCE_DIR}/.. )
set( DEP_PATH ${ROOT_PATH}/dependence )
set( INC_PATH ${ROOT_PATH}/core/include )
set( SRC_PATH ${ROOT_PATH}/core/source )
set( LOGIC_PATH ${ROOT_PATH}/logic )
set( BIN_PATH ${ROOT_PATH}/${__WORKSPACE__}/binary )

set(EXECUTABLE_OUTPUT_PATH ${BIN_PATH})
##############################################################
set( MAIN_SRC  ${SRC_PATH}/Main.cpp )
##############################################################
set(archivei ${INC_PATH}/archive )
set(archives ${SRC_PATH}/archive )

set( ARCHIVE_SRC
	${archives}/Archive.cpp
	${archives}/ArchiveHash.cpp
	${archives}/ArchiveHead.cpp
	${archives}/ArchiveReader.cpp
	${archives}/ArchiveService.cpp
	${archives}/ArchiveWriter.cpp
	${archives}/BinReader.cpp
	${archives}/BinWriter.cpp
	${archives}/JourneyDescripter.cpp
	${archives}/LogWriter.cpp
	${archives}/XmlReader.cpp)

SET( ARCHIVE_H
	${archivei}/Archive.h
	${archivei}/ArchiveHash.h
	${archivei}/ArchiveHead.h
	${archivei}/ArchiveReader.h
	${archivei}/ArchiveService.h
	${archivei}/ArchiveWriter.h
	${archivei}/BinReader.h
	${archivei}/BinWriter.h
	${archivei}/IJourney.h
	${archivei}/JourneyDescripter.h
	${archivei}/LogWriter.h
	${archivei}/rapidxml.hpp
	${archivei}/rapidxml_iterators.hpp
	${archivei}/rapidxml_print.hpp
	${archivei}/rapidxml_utils.hpp
	${archivei}/XmlReader.h)
##############################################################
set(closedi ${INC_PATH}/closed )
set(closeds ${SRC_PATH}/closed )

set( CLOSED_SRC
	${closeds}/C2SClosed.cpp
	${closeds}/Closed.cpp
	${closeds}/ClosedMgr.cpp
	${closeds}/ClosedModule.cpp
	${closeds}/ClosedProtocol.cpp
	${closeds}/Closeds.cpp
	${closeds}/ClosedService.cpp
	${closeds}/DoingService.cpp
	${closeds}/IndexValue.cpp
	${closeds}/S2CClosed.cpp)

SET( CLOSED_H
	${closedi}/C2SClosed.h
	${closedi}/Closed.h
	${closedi}/ClosedMgr.h
	${closedi}/ClosedModule.h
	${closedi}/ClosedProtocol.h
	${closedi}/Closeds.h
	${closedi}/ClosedService.h
	${closedi}/DoingService.h
	${closedi}/IDoing.h
	${closedi}/IndexValue.h
	${closedi}/S2CClosed.h)
##############################################################
set(compressi ${INC_PATH}/compress )
set(compresss ${SRC_PATH}/compress )

set( COMPRESS_SRC
	${compresss}/CompressService.cpp )

SET( COMPRESS_H
	${compressi}/CompressService.h )
##############################################################
set( cpui ${INC_PATH}/cpu )
set( cpus ${SRC_PATH}/cpu )

set( CPU_SRC
	${cpus}/CpuService.cpp )

SET( CPU_H
	${cpui}/CpuService.h )
##############################################################
set( crci ${INC_PATH}/crc )
set( crcs ${SRC_PATH}/crc )

set( CRC_SRC
	${crcs}/CrcService.cpp )

SET( CRC_H
	${crci}/CrcService.h )
##############################################################
set( handlei ${INC_PATH}/handle )
set( handles ${SRC_PATH}/handle )

set( HANDLE_SRC
	${handles}/Context.cpp
	${handles}/Handle.cpp
	${handles}/HandleService.cpp)

SET( HANDLE_H
	${handlei}/Context.h
	${handlei}/Handle.h
	${handlei}/HandleService.h)
##############################################################
set( includei ${INC_PATH}/include )
set( includes ${SRC_PATH}/include )

set( INCLUDE_SRC
	${includes}/Preinit.cpp)

SET( INCLUDE_H
	${includei}/Convert.h
	${includei}/Default.h
	${includei}/DefInc.h
	${includei}/ERRORINT.h
	${includei}/LibInc.h
	${includei}/Preinit.h
	${includei}/Singleton.h
	${includei}/StdInc.h
	${includei}/TypeInc.h)
##############################################################
set( initi ${INC_PATH}/init )
set( inits ${SRC_PATH}/init )

set( INIT_SRC
	${inits}/InitService.cpp)

SET( INIT_H
	${initi}/InitService.h
	${initi}/InitType_.h )
##############################################################
set( ioservicei ${INC_PATH}/ioservice )
set( ioservices ${SRC_PATH}/ioservice )

set( IOSERVICE_SRC
	${ioservices}/IoService.cpp)

SET( IOSERVICE_H
	${ioservicei}/IoService.h)
##############################################################
set( logi ${INC_PATH}/log )
set( logs ${SRC_PATH}/log )

set( LOG_SRC
	${logs}/LogService.cpp)

SET( LOG_H
	${logi}/LogService.h)
##############################################################
set( luai ${INC_PATH}/lua )
set( luas ${SRC_PATH}/lua )

set( LUA_SRC
	${luas}/LuaScript.cpp
	${luas}/LuaService.cpp
	${luas}/LuaWriter.cpp)

SET( LUA_H
	${luai}/LuaScript.h
	${luai}/LuaService.h
	${luai}/LuaWriter.h)
##############################################################
set( neti ${INC_PATH}/net )
set( nets ${SRC_PATH}/net )

set( NET_SRC
	${nets}/IPacket.cpp
	${nets}/IProtocol.cpp
	${nets}/Player.cpp
	${nets}/PlayerService.cpp
	${nets}/ProtocolService.cpp
	${nets}/ReadBlock.cpp
	${nets}/Robot.cpp
	${nets}/Session.cpp
	${nets}/SingleWire.cpp
	${nets}/TcpClient.cpp
	${nets}/TcpServer.cpp
	${nets}/WriteBlock.cpp )

SET( NET_H
	${neti}/IBlock.h
	${neti}/IPacket.h
	${neti}/IProtocol.h
	${neti}/Player.h
	${neti}/PlayerService.h
	${neti}/ProtocolService.h
	${neti}/ReadBlock.h
	${neti}/Robot.h
	${neti}/Session.h
	${neti}/SingleWire.h
	${neti}/TcpClient.h
	${neti}/TcpServer.h
	${neti}/WriteBlock.h)	
##############################################################
set( projInci ${INC_PATH}/projInc )

SET( PROJINC_H
	${projInci}/CocoClient.h
	${projInci}/GameClient.h
	${projInci}/GameServer.h
	${projInci}/LoginServer.h)
##############################################################
set( propertyi ${INC_PATH}/property )
set( propertys ${SRC_PATH}/property )

set( PROPERTY_SRC
	${propertys}/Property.cpp
	${propertys}/PropertyMgr.cpp
	${propertys}/PropertySink.cpp)

SET( PROPERTY_H
	${propertyi}/IPropertyId.h
	${propertyi}/Property.h
	${propertyi}/PropertyId.h
	${propertyi}/PropertyMgr.h
	${propertyi}/PropertySink.h)
##############################################################
set( randomi ${INC_PATH}/random )
set( randoms ${SRC_PATH}/random )

set( RANDOM_SRC
	${randoms}/RandomService.cpp)

SET( RANDOM_H
	${randomi}/RandomService.h)
##############################################################
set( settingi ${INC_PATH}/setting )
set( settings ${SRC_PATH}/setting )

set( SETTING_SRC
	${settings}/SettingService.cpp)

SET( SETTING_H
	${settingi}/SettingService.h)
##############################################################
set( timei ${INC_PATH}/time )
set( times ${SRC_PATH}/time )

set( TIME_SRC
	${times}/TimeService.cpp)

SET( TIME_H
	${timei}/TimeService.h)
##############################################################
set( valuei ${INC_PATH}/value )
set( values ${SRC_PATH}/value )

set( VALUE_SRC
	${values}/IValue.cpp
	${values}/ValueList.cpp
	${values}/Values.cpp)

SET( VALUE_H
	${valuei}/IValue.h
	${valuei}/ValueList.h
	${valuei}/Values.h)
##############################################################
set(pings ${LOGIC_PATH}/ping )

set( PING_SRC
	${pings}/C2SPing.cpp
	${pings}/PingProtocol.cpp
	${pings}/PingSecond.cpp
	${pings}/PingTick.cpp
	${pings}/S2CPing.cpp)

SET( PING_H
	${pings}/C2SPing.h
	${pings}/PingProtocol.h
	${pings}/PingSecond.h
	${pings}/PingTick.h
	${pings}/S2CPing.h)
##############################################################
add_subdirectory(libbzlib)
add_subdirectory(liblua)

add_executable(${PROJECT_NAME} 
	${MAIN_SRC}
	${ARCHIVE_SRC} ${ARCHIVE_H}
	${CLOSED_SRC} ${CLOSED_H}
	${COMPRESS_SRC} ${COMPRESS_H}
	${CPU_SRC} ${CPU_H}
	${CRC_SRC} ${CRC_H}
	${HANDLE_SRC} ${HANDLE_H}
	${INCLUDE_SRC} ${INCLUDE_H}
	${INIT_SRC} ${INIT_H}
	${IOSERVICE_SRC} ${IOSERVICE_H}
	${LOG_SRC} ${LOG_H}
	${LUA_SRC} ${LUA_H}
	${NET_SRC} ${NET_H}
	${PROJINC_H}
	${PROPERTY_SRC} ${PROPERTY_H}
	${RANDOM_SRC} ${RANDOM_H}
	${SETTING_SRC} ${SETTING_H}
	${TIME_SRC} ${TIME_H}
	${VALUE_SRC} ${VALUE_H}
	${PING_SRC} ${PING_H})
	
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} libbzlib liblua)
