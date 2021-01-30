cmake_minimum_required(VERSION 2.8.12)
project(TurnPlayer)

add_definitions("-std=c++11 -W -Wall -Wextra")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/src/lib/include)
find_library(soloud libsoloud.a "${CMAKE_SOURCE_DIR}/src/lib")

add_executable(main
	src/main.cpp
	src/AudioPlayer.cpp)

target_link_libraries(main ${soloud} pthread ${SDL2_LIBRARIES})