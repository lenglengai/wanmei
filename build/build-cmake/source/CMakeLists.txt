cmake_minimum_required(VERSION 3.0)

project(${__PROJECT__})

string(TOUPPER ${__PROJECT__} __PROJNAME__)
add_definitions(-D__${__PROJNAME__}__)

if(WIN32)
  add_definitions("-D_WIN32_WINNT=0x0601")
  set(CMAKE_C_FLAGS_DEBUG   "/MD /Zi /Od /Ob0 /RTC1")
  set(CMAKE_CXX_FLAGS_DEBUG "/MD /Zi /Od /Ob0 /RTC1")
  set(CMAKE_C_FLAGS_RELEASE   "/MT /O2 /Ob2 /DNDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /DNDEBUG")
  set(CMAKE_EXE_LINKER_FLAGS "/MANIFEST:NO")
else()
  set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

include_directories(../../../${__WORKSPACE__}/inc)
include_directories($ENV{BOOST_ROOT})
link_directories($ENV{BOOST_ROOT}/stage/lib)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system date_time regex chrono thread filesystem log log_setup REQUIRED)

aux_source_directory(. MAIN_SRC)

file(STRINGS ../../../source/CPPLISTS SOURCELISTS)
separate_arguments(SOURCELISTS)

add_executable(${PROJECT_NAME} ${MAIN_SRC} ${SOURCELISTS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
