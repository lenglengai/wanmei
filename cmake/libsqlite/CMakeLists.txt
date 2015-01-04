project(sqlite)

set(prefixs ${DEP_PATH}/${PROJECT_NAME})

set( sources
	${prefixs}/sqlite3.c)

SET( headers
	${prefixs}/sqlite3.h
	${prefixs}/sqlite3ext.h)
	
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_library(libsqlite STATIC ${sources} ${headers})

unset(headers)
unset(sources)
unset(prefixs)
