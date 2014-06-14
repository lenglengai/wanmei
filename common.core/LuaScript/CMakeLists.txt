aux_source_directory(. SRC_LIST)
aux_source_directory(./lua SRC_LIST0)
add_library(LuaScript ${SRC_LIST} ${SRC_LIST0})
