cmake_minimum_required(VERSION 3.6.2)

project(FireBlocks)

if(WIN32)
	add_definitions(-DFB_WIN)
elseif(APPLE)
	add_definitions(-DFB_OSX)
else()
	message(FATAL_ERROR "Undefined platform")
endif()

#includes
set(SDL_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2-2.0.9_WIN/include")
set(SDL_NET_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2_net-2.0.1_WIN/include")

#libs
set(SDL_LIB_PATH)
set(SDL_NET_LIB_PATH)

if(WIN32)
	set(SDL_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2-2.0.9_WIN/lib/x86")
	set(SDL_NET_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/SDL2_net-2.0.1_WIN/lib/x86")
elseif(APPLE)
	set(SDL_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/")
	set(SDL_NET_LIB_PATH "${CMAKE_SOURCE_DIR}/external/sdl/")
else()
	message(FATAL_ERROR "Unsupported platform")
endif()

add_subdirectory(src/game/)