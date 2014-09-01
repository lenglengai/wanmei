cmake_minimum_required(VERSION 3.0)

project(configure)
add_definitions("-D__CONFIGURE__")

if(WIN32)
  ADD_DEFINITIONS("-D_WIN32_WINNT=0x0601")
endif()

include_directories(${__PROJDIR__}/include)
include_directories($ENV{BOOST_ROOT})
link_directories($ENV{BOOST_ROOT}/stage/lib)
set(Boost_USE_STATIC_LIBS ON)
if(WIN32)
	FIND_PACKAGE(Boost 1.55.0 COMPONENTS log log_setup system thread filesystem date_time REQUIRED)
elseif(APPLE)
	FIND_PACKAGE(Boost 1.55.0 COMPONENTS log log_setup system filesystem date_time REQUIRED)
endif()

AUX_SOURCE_DIRECTORY(. MAIN_SRC)

file(STRINGS ../../../source/CPPLISTS SOURCELISTS)
separate_arguments(SOURCELISTS)

add_executable(${PROJECT_NAME} ${MAIN_SRC} ${SOURCELISTS})
