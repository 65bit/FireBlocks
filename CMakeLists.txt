cmake_minimum_required(VERSION 3.6.2)

project(FireBlocks)

if(WIN32)
	add_definitions(-DFB_WIN)
elseif(APPLE)
	add_definitions(-DFB_OSX)
else()
	message(FATAL_ERROR "Undefined platform")
endif()

add_subdirectory(src)