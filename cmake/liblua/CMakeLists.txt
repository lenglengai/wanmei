project(lua)

set(prefixs ${DEP_PATH}/${PROJECT_NAME} )

set( sources
	${prefixs}/lapi.c
	${prefixs}/lauxlib.c
	${prefixs}/lbaselib.c
	${prefixs}/lcode.c
	${prefixs}/ldblib.c
	${prefixs}/ldebug.c
	${prefixs}/ldo.c
	${prefixs}/ldump.c
	${prefixs}/lfunc.c
	${prefixs}/lgc.c
	${prefixs}/linit.c
	${prefixs}/liolib.c
	${prefixs}/llex.c
	${prefixs}/lmathlib.c
	${prefixs}/lmem.c
	${prefixs}/loadlib.c
	${prefixs}/lobject.c
	${prefixs}/lopcodes.c
	${prefixs}/loslib.c
	${prefixs}/lparser.c
	${prefixs}/lstate.c
	${prefixs}/lstring.c
	${prefixs}/lstrlib.c
	${prefixs}/ltable.c
	${prefixs}/ltablib.c
	${prefixs}/ltm.c
	${prefixs}/lundump.c
	${prefixs}/lvm.c
	${prefixs}/lzio.c
	${prefixs}/print.c
	${prefixs}/lua_tinker.cpp)

SET( headers
	${prefixs}/lapi.h
	${prefixs}/lauxlib.h
	${prefixs}/lcode.h
	${prefixs}/ldebug.h
	${prefixs}/ldo.h
	${prefixs}/lfunc.h
	${prefixs}/lgc.h
	${prefixs}/llex.h
	${prefixs}/llimits.h
	${prefixs}/lmem.h
	${prefixs}/lobject.h
	${prefixs}/lopcodes.h
	${prefixs}/lparser.h
	${prefixs}/lstate.h
	${prefixs}/lstring.h
	${prefixs}/ltable.h
	${prefixs}/ltm.h
	${prefixs}/lua.h
	${prefixs}/luaconf.h
	${prefixs}/lualib.h
	${prefixs}/lundump.h
	${prefixs}/lvm.h
	${prefixs}/lzio.h
	${prefixs}/lua_tinker.h	)
	
add_definitions( -D_CRT_SECURE_NO_WARNINGS)
add_library( liblua STATIC ${sources} ${headers} )

unset(headers)
unset(sources)
unset(prefixs)
