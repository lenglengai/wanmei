AUX_SOURCE_DIRECTORY(. STARTUP_LIST)
AUX_SOURCE_DIRECTORY(../com.lua LUA_LIST0)
AUX_SOURCE_DIRECTORY(../com.lua/lua LUA_LIST1)
AUX_SOURCE_DIRECTORY(../com.log LOG_LIST)
AUX_SOURCE_DIRECTORY(../com.crc CRC_LIST)
AUX_SOURCE_DIRECTORY(../com.setting SETTING_LIST)
configure_file("../com.setting/config/setting.xml"
                "${PROJECT_BINARY_DIR}/config/setting.xml" COPYONLY)
AUX_SOURCE_DIRECTORY(../com.shiny SHINY_LIST)
AUX_SOURCE_DIRECTORY(../com.handle HANDLE_LIST)
configure_file("../com.handle/config/handle.xml"
                "${PROJECT_BINARY_DIR}/config/handle.xml" COPYONLY)
AUX_SOURCE_DIRECTORY(../com.ioservice IOSERVICE_LIST)
configure_file("../com.ioService/config/ioService.xml"
                "${PROJECT_BINARY_DIR}/config/ioService.xml" COPYONLY)
AUX_SOURCE_DIRECTORY(../com.init INIT_LIST)
AUX_SOURCE_DIRECTORY(../com.block BLOCK_LIST)
AUX_SOURCE_DIRECTORY(../com.packet PACKET_LIST)
AUX_SOURCE_DIRECTORY(../com.server SERVER_LIST)
configure_file("../com.server/config/server.xml"
                "${PROJECT_BINARY_DIR}/config/server.xml" COPYONLY)
AUX_SOURCE_DIRECTORY(../com.client CLIENT_LIST)
add_executable(${PROJECT_NAME}  ${STARTUP_LIST} ${LUA_LIST0} ${LUA_LIST1} ${LOG_LIST}
 ${CRC_LIST} ${SETTING_LIST} ${SHINY_LIST} ${HANDLE_LIST} ${INIT_LIST}  ${IOSERVICE_LIST} 
 ${BLOCK_LIST} ${PACKET_LIST} ${SERVER_LIST} ${CLIENT_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} libws2_32.a libwsock32.a)
