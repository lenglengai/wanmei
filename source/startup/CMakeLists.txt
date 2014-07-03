AUX_SOURCE_DIRECTORY(. STARTUP_LIST)


AUX_SOURCE_DIRECTORY(../common/lua LUA_LIST0)
AUX_SOURCE_DIRECTORY(../common/lua/lua LUA_LIST1)
AUX_SOURCE_DIRECTORY(../common/shiny SHINY_LIST)


AUX_SOURCE_DIRECTORY(../service/crc CRC_LIST)
AUX_SOURCE_DIRECTORY(../service/handle HANDLE_LIST)
configure_file("../service/handle/config/handle.xml"
	"${PROJECT_BINARY_DIR}/config/handle.xml" COPYONLY)
AUX_SOURCE_DIRECTORY(../service/init INIT_LIST)
AUX_SOURCE_DIRECTORY(../service/ioservice IOSERVICE_LIST)
configure_file("../service/ioservice/config/ioService.xml"
	"${PROJECT_BINARY_DIR}/config/ioService.xml" COPYONLY)
AUX_SOURCE_DIRECTORY(../service/log LOG_LIST)
AUX_SOURCE_DIRECTORY(../service/random RANDOM_LIST)
AUX_SOURCE_DIRECTORY(../service/setting SETTING_LIST)
configure_file("../service/setting/config/setting.xml"
	"${PROJECT_BINARY_DIR}/config/setting.xml" COPYONLY)
AUX_SOURCE_DIRECTORY(../service/time TIME_LIST)


AUX_SOURCE_DIRECTORY(../net/block BLOCK_LIST)
AUX_SOURCE_DIRECTORY(../net/client CLIENT_LIST)
AUX_SOURCE_DIRECTORY(../net/packet PACKET_LIST)
AUX_SOURCE_DIRECTORY(../net/server SERVER_LIST)
configure_file("../net/server/config/server.xml"
	"${PROJECT_BINARY_DIR}/config/server.xml" COPYONLY)


AUX_SOURCE_DIRECTORY(../logic/ping PING_LIST)


add_executable(${PROJECT_NAME}  ${STARTUP_LIST} 
	${LUA_LIST0} ${LUA_LIST1} ${SHINY_LIST}
	${CRC_LIST} ${HANDLE_LIST} ${INIT_LIST} ${IOSERVICE_LIST}
	${LOG_LIST} ${RANDOM_LIST} ${SETTING_LIST} ${TIME_LIST}
	${BLOCK_LIST} ${CLIENT_LIST} ${PACKET_LIST} ${SERVER_LIST} 
	${PING_LIST})

if(MINGW)
	target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ws2_32 wsock32)
endif()
