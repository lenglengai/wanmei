project(logic)

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
add_library( liblogic STATIC 
	${PING_SRC} ${PING_H})
