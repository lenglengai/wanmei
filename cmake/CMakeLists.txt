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
set( MAIN_H  ${SRC_PATH}/Include.h 
		${SRC_PATH}/Logic.h )
##############################################################
set( commons ${SRC_PATH}/common )

set( COMMON_SRC
	${commons}/classid.cpp
	${commons}/versionid.cpp
	${commons}/default.cpp)

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
	${cores}/InitService.cpp
	${cores}/Console.cpp 
	${cores}/Property.cpp 
	${cores}/PropertyMgr.cpp 
	${cores}/PropertySink.cpp 
	${cores}/CommandBat.cpp )

SET( CORE_H
	${cores}/Service.h
	${cores}/InitService.h
	${cores}/Console.h 
	${cores}/IPropertyId.h 
	${cores}/Property.h
	${cores}/PropertyId.h 
	${cores}/PropertyMgr.h 
	${cores}/PropertySink.h 
	${cores}/CommandBat.h )
##############################################################
set( accounts ${SRC_PATH}/account )

set( ACCOUNT_SRC
	${accounts}/AccountTB.cpp
	${accounts}/AccountService.cpp 
	${accounts}/AccountAll.cpp 
	${accounts}/Account.cpp )

SET( ACCOUNT_H
	${accounts}/AccountTB.h
	${accounts}/AccountService.h
	${accounts}/AccountAll.h 
	${accounts}/Account.h )
##############################################################
set( services ${SRC_PATH}/service )

set( SERVICE_SRC
	${services}/StringWriter.cpp
	${services}/CommandArgs.cpp
	${services}/IService.cpp
	${services}/CrcService.cpp 
	${services}/Context.cpp 
	${services}/Handle.cpp 
	${services}/HandleService.cpp
	${services}/LogService.cpp
	${services}/TimeService.cpp
	${services}/DebugService.cpp
	${services}/LuaEngine.cpp
	${services}/LuaService.cpp
	${services}/CompressService.cpp
	${services}/RandomService.cpp)

SET( SERVICE_H
	${services}/StringWriter.h
	${services}/CommandArgs.h
	${services}/IService.h
	${services}/CrcService.h 
	${services}/Context.h 
	${services}/Handle.h 
	${services}/HandleService.h
	${services}/LogService.h
	${services}/TimeService.h
	${services}/LuaEngine.h
	${services}/LuaService.h
	${services}/CompressService.h
	${services}/RandomService.h
	${services}/DebugService.h)
	
file(COPY ${services}/handleServer.xml DESTINATION ${BIN_PATH})
file(COPY ${services}/handleClient.xml DESTINATION ${BIN_PATH})
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
	${sessions}/SessionService.cpp 
	${sessions}/TcpServer.cpp 
	${sessions}/TcpClient.cpp )

SET( SESSION_H
	${sessions}/IBlock.h
	${sessions}/WriteBlock.h
	${sessions}/ReadBlock.h
	${sessions}/IPacket.h
	${sessions}/Session.h
	${sessions}/SessionService.h
	${sessions}/IProtocol.h
	${sessions}/ProtocolService.h
	${sessions}/IoService.h 
	${sessions}/TcpServer.h 
	${sessions}/TcpClient.h )
file(COPY ${sessions}/ioClient.xml DESTINATION ${BIN_PATH})
file(COPY ${sessions}/ioServer.xml DESTINATION ${BIN_PATH})
file(COPY ${sessions}/tcpAddress.xml DESTINATION ${BIN_PATH})
##############################################################
set(dbs ${SRC_PATH}/db )

set( DBS_SRC
	${dbs}/SqlCommand.cpp
	${dbs}/IDataBase.cpp
	${dbs}/MySqlQuery.cpp
	${dbs}/MySqlConnection.cpp
	${dbs}/MySqlDataBase.cpp
	${dbs}/DbService.cpp 
	${dbs}/SqliteDataBase.cpp
	${dbs}/SqliteQuery.cpp )

SET( DBS_H
	${dbs}/SqlType_.h
	${dbs}/SqlFieldId_.h
	${dbs}/SqlDeal_.h
	${dbs}/ISqlStream.h
	${dbs}/ISqlHeadstream.h
	${dbs}/SqlCommand.h
	${dbs}/IDbQuery.h
	${dbs}/IDataBase.h
	${dbs}/MySqlQuery.h
	${dbs}/MySqlConnection.h
	${dbs}/MySqlDataBase.h
	${dbs}/SqliteQuery.h
	${dbs}/SqliteDataBase.h
	${dbs}/DbService.h)
file(COPY ${dbs}/gameDb.xml DESTINATION ${BIN_PATH})
file(COPY ${dbs}/loginDb.xml DESTINATION ${BIN_PATH})
file(COPY ${dbs}/logDb.xml DESTINATION ${BIN_PATH})
file(COPY ${dbs}/libmysql.dll DESTINATION ${BIN_PATH})
##############################################################
set(worlds ${SRC_PATH}/world )

set( WORLD_SRC
	${worlds}/WorldService.cpp 
	${worlds}/World.cpp 
	${worlds}/Tourist.cpp 
	${worlds}/Player.cpp )

SET( WORLD_H
	${worlds}/WorldService.h 
	${worlds}/World.h 
	${worlds}/Tourist.h 
	${worlds}/Player.h )
	
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
add_subdirectory(libsqlite)

add_executable(${PROJECT_NAME} ${MAIN_H}
	${COMMON_SRC} ${COMMON_H} 
	${CORE_SRC} ${CORE_H}
	${ACCOUNT_SRC} ${ACCOUNT_H}
	${SERVICE_SRC} ${SERVICE_H}
	${ARCHIVE_SRC} ${ARCHIVE_H}
	${SESSION_SRC} ${SESSION_H}	
	${DBS_SRC} ${DBS_H} 
	${WORLD_SRC} ${WORLD_H} 
	${PING_SRC} ${PING_H} )
	
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} libbzlib liblua libsqlite libmysql)
