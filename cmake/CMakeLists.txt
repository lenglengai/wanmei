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

include_directories($ENV{MYSQL_ROOT}/include/mysql)
link_directories($ENV{MYSQL_ROOT}/lib)

include_directories($ENV{BOOST_ROOT})
link_directories($ENV{BOOST_ROOT}/stage/lib)
set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost COMPONENTS system date_time regex chrono thread filesystem log log_setup REQUIRED)

##############################################################
set( ROOT_PATH ${CMAKE_SOURCE_DIR}/.. )
set( DEP_PATH ${ROOT_PATH}/dependence )
set( SRC_PATH ${ROOT_PATH}/source )
set( BIN_PATH ${ROOT_PATH}/${__WORKSPACE__}/binary )

set(EXECUTABLE_OUTPUT_PATH ${BIN_PATH})
##############################################################
set( MAIN_SRC  ${SRC_PATH}/Main.cpp )
set( MAIN_H  ${SRC_PATH}/Include.h )
##############################################################
set( commons ${SRC_PATH}/common )

set( COMMON_SRC
	${commons}/classid.cpp
	${commons}/versionid.cpp)

SET( COMMON_H
	${commons}/definc.h
	${commons}/typeinc.h
	${commons}/error_.h
	${commons}/stdinc.h
	${commons}/libinc.h
	${commons}/default.h
	${commons}/singleton.h
	${commons}/noncopyable.h
	${commons}/convert.h
	${commons}/classid.h
	${commons}/versionid.h)
##############################################################
set( cores ${SRC_PATH}/core )

set( CORE_SRC
	${cores}/StringWriter.cpp
	${cores}/CommandArgs.cpp
	${cores}/IService.cpp
	${cores}/ServiceMgr.cpp
	${cores}/Preinit.cpp
	${cores}/CrcService.cpp 
	${cores}/Context.cpp 
	${cores}/Handle.cpp 
	${cores}/HandleService.cpp
	${cores}/LogService.cpp
	${cores}/InitService.cpp
	${cores}/TimeService.cpp
	${cores}/DebugService.cpp
	${cores}/LuaEngine.cpp
	${cores}/LuaService.cpp
	${cores}/CompressService.cpp
	${cores}/RandomService.cpp
	${cores}/TimeService.cpp
	${cores}/Console.cpp 
	${cores}/Property.cpp 
	${cores}/PropertyMgr.cpp 
	${cores}/PropertySink.cpp 
	${cores}/Console.cpp )

SET( CORE_H
	${cores}/StringWriter.h
	${cores}/CommandArgs.h
	${cores}/IService.h
	${cores}/ServiceMgr.h
	${cores}/Preinit.h
	${cores}/CrcService.h 
	${cores}/Context.h 
	${cores}/Handle.h 
	${cores}/HandleService.h
	${cores}/LogService.h
	${cores}/InitService.h
	${cores}/TimeService.h
	${cores}/LuaEngine.h
	${cores}/LuaService.h
	${cores}/CompressService.h
	${cores}/RandomService.h
	${cores}/TimeService.h
	${cores}/DebugService.h
	${cores}/Console.h 
	${cores}/IPropertyId.h 
	${cores}/Property.h
	${cores}/PropertyId.h 
	${cores}/PropertyMgr.h 
	${cores}/PropertySink.h 
	${cores}/Console.h )
file(COPY ${cores}/handleServer.xml DESTINATION ${BIN_PATH})
file(COPY ${cores}/handleClient.xml DESTINATION ${BIN_PATH})
##############################################################
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
	${archives}/XmlReader.cpp)

SET( ARCHIVE_H
	${archives}/Archive.h
	${archives}/ArchiveHash.h
	${archives}/ArchiveHead.h
	${archives}/ArchiveReader.h
	${archives}/ArchiveService.h
	${archives}/ArchiveWriter.h
	${archives}/BinReader.h
	${archives}/BinWriter.h
	${archives}/rapidxml.hpp
	${archives}/rapidxml_iterators.hpp
	${archives}/rapidxml_print.hpp
	${archives}/rapidxml_utils.hpp
	${archives}/XmlReader.h)
##############################################################
set(sessions ${SRC_PATH}/session )

set( SESSION_SRC
	${sessions}/IoService.cpp
	${sessions}/IPacket.cpp
	${sessions}/IProtocol.cpp
	${sessions}/ProtocolService.cpp
	${sessions}/ReadBlock.cpp
	${sessions}/WriteBlock.cpp
	${sessions}/Session.cpp
	${sessions}/SessionService.cpp )

SET( SESSION_H
	${sessions}/IBlock.h
	${sessions}/WriteBlock.h
	${sessions}/ReadBlock.h
	${sessions}/IPacket.h
	${sessions}/Session.h
	${sessions}/SessionService.h
	${sessions}/IProtocol.h
	${sessions}/ProtocolService.h
	${sessions}/IoService.h )
file(COPY ${sessions}/ioClient.xml DESTINATION ${BIN_PATH})
file(COPY ${sessions}/ioServer.xml DESTINATION ${BIN_PATH})
##############################################################
set(players ${SRC_PATH}/player )

set( PLAYER_SRC
	${tcpClients}/Robot.cpp 
	${tcpClients}/Tourist.cpp 
	${tcpClients}/Player.cpp )

SET( PLAYER_H
	${tcpClients}/Robot.h 
	${tcpClients}/Tourist.h 
	${tcpClients}/Player.h )
##############################################################
set(tcpServers ${SRC_PATH}/tcpServer )

set( TCPSERVER_SRC
	${tcpServers}/TcpServer.cpp )

SET( TCPSERVER_H
	${tcpServers}/TcpServer.h )
file(COPY ${tcpServers}/tcpAddress.xml DESTINATION ${BIN_PATH})
##############################################################
set(tcpClients ${SRC_PATH}/tcpClient )

set( TCPCLIENT_SRC
	${tcpClients}/TcpClient.cpp )

SET( TCPCLIENT_H
	${tcpClients}/TcpClient.h )
##############################################################
set(worlds ${SRC_PATH}/world )

set( WORLD_SRC
	${worlds}/WorldService.cpp 
	${worlds}/World.cpp )

SET( WORLD_H
	${worlds}/WorldService.h 
	${worlds}/World.h )
file(COPY ${worlds}/worldClient.xml DESTINATION ${BIN_PATH})
file(COPY ${worlds}/worldServer.xml DESTINATION ${BIN_PATH})
##############################################################
set(pings ${SRC_PATH}/ping )

set( PING_SRC
	${pings}/S2CPing.cpp 
	${pings}/PingTick.cpp 
	${pings}/PingProtocol.cpp 
	${pings}/C2SPing.cpp )

SET( PING_H
	${pings}/S2CPing.h 
	${pings}/PingTick.h 
	${pings}/PingProtocol.h 
	${pings}/C2SPing.h )
##############################################################
add_subdirectory(libbzlib)
add_subdirectory(liblua)

add_executable(${PROJECT_NAME}
	${MAIN_SRC} ${MAIN_H}
	${COMMON_SRC} ${COMMON_H} 
	${CORE_SRC} ${CORE_H}
	${ARCHIVE_SRC} ${ARCHIVE_H}
	${SESSION_SRC} ${SESSION_H}	
	${TCPSERVER_SRC} ${TCPSERVER_H} 
	${TCPCLIENT_SRC} ${TCPCLIENT_H} 
	${WORLD_SRC} ${WORLD_H} 
	${PING_SRC} ${PING_H} )
	
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} libbzlib liblua libmysql)
