cmake_minimum_required(VERSION 3.1)

project(RNSsign)

set(CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wendif-labels " )

set(TSOURCES catch/catch_main.cpp)
file(GLOB SOURCES "src/*.cpp")
add_executable(RNSsign ${SOURCES} ${TSOURCES})