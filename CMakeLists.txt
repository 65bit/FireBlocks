cmake_minimum_required(VERSION 3.6.2)

project(FireBlocks)

if(NOT WIN32 AND NOT APPLE)
	message(FATAL_ERROR "Unsupported platform")
endif()

if(WIN32)
	add_definitions(-DFB_WIN)
elseif(APPLE)
	add_definitions(-DFB_OSX)
endif()

set(MODULES_ROOT "${CMAKE_SOURCE_DIR}/src")
set(EXTERNAL_ROOT "${CMAKE_SOURCE_DIR}/external")

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

#Build 

add_subdirectory(src/engine/)
add_subdirectory(src/game/)