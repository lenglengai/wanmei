cmake_minimum_required(VERSION 3.0)

if (__CLIENT__)
	project(client)
	add_definitions("-D__CLIENT__")
elseif(__SERVER__)
	project(server)
	add_definitions("-D__SERVER__")
elseif(__LOGIN__)
	project(login)
	add_definitions("-D__LOGIN__")
endif()

if(WIN32)
  ADD_DEFINITIONS("-D_WIN32_WINNT=0x0601")
endif()
if(APPLE)
	set(CMAKE_CXX_FLAGS "-std=c++11")
endif()


include_directories(${__PROJDIR__}/include)
include_directories($ENV{BOOST_ROOT})
link_directories($ENV{BOOST_ROOT}/stage/lib)
set(Boost_USE_STATIC_LIBS ON)
if(WIN32)
	FIND_PACKAGE(Boost 1.56.0 COMPONENTS log log_setup system thread filesystem date_time REQUIRED)
elseif(APPLE)
	FIND_PACKAGE(Boost 1.56.0 COMPONENTS log log_setup system thread filesystem date_time REQUIRED)
endif()

AUX_SOURCE_DIRECTORY(. MAIN_SRC)

file(STRINGS ../../../source/CPPLISTS SOURCELISTS)
separate_arguments(SOURCELISTS)

add_executable(${PROJECT_NAME} ${MAIN_SRC} ${SOURCELISTS})
