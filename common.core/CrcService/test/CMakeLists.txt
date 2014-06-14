project(testMain)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "-std=c++0x")

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.55.0 COMPONENTS date_time)

include_directories($ENV{BOOST})
aux_source_directory(. SRC_LIST)
aux_source_directory(.. SRC_LIST0)
add_executable(testMain ${SRC_LIST} ${SRC_LIST0})
target_link_libraries(testMain $ENV{BOOST}/stage/lib)
