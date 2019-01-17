cmake_minimum_required(VERSION 3.6.2)

project(FireBlocks)

if(WIN32)
	add_definitions(-DFB_WIN)
elseif(APPLE)
	add_definitions(-DFB_OSX)
else()
	message(FATAL_ERROR "Undefined platform")
endif()

#Includes

set(SDL_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2-2.0.9_WIN/include")
set(SDL_NET_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2_net-2.0.1_WIN/include")

#Libs

set(SDL_LIB_PATH)
set(SDL_NET_LIB_PATH)

#Etc
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

if(WIN32)
	set(SDL_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2-2.0.9_WIN/lib/x86")
	set(SDL_NET_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2_net-2.0.1_WIN/lib/x86")
elseif(APPLE)
	set(SDL_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/")
	set(SDL_NET_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/")
else()
	message(FATAL_ERROR "Unsupported platform")
endif()

#Build 

add_subdirectory(src/engine/)
add_subdirectory(src/game/)