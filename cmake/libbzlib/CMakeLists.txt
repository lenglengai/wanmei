project(bzlib)

set(prefixs ${DEP_PATH}/${PROJECT_NAME})

set(sources 
	${prefixs}/blocksort.c
    ${prefixs}/bzlib.c
    ${prefixs}/compress.c
    ${prefixs}/crctable.c
    ${prefixs}/decompress.c
    ${prefixs}/huffman.c
    ${prefixs}/randtable.c )

set(headers 
	${prefixs}/bzlib.h
    ${prefixs}/bzlib_private.h )

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_library( libbzlib STATIC ${sources} ${headers})

unset(headers)
unset(sources)
unset(prefixs)
