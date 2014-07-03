cmake_minimum_required(VERSION 3.0)

if (__CLIENT__)
	project(client.startup)
	add_definitions("-D__CLIENT__")
elseif(__SERVER__)
	project(server.startup)
	add_definitions("-D__SERVER__")
endif()

add_definitions("-D_DEBUG")
set(CMAKE_BUILD_TYPE Debug)

if(WIN32)
  ADD_DEFINITIONS("-D_WIN32_WINNT=0x0601")
endif()

if(MINGW)
	set(CMAKE_CXX_FLAGS "-std=c++0x -U__STRICT_ANSI__")
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-s")
endif()

include_directories(${__INCLUDE__})
include_directories($ENV{BOOST_ROOT})
link_directories($ENV{BOOST_ROOT}/stage/lib)
set(Boost_USE_STATIC_LIBS ON)
FIND_PACKAGE(Boost 1.55.0 COMPONENTS log log_setup system thread filesystem date_time REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
add_subdirectory(startup)
