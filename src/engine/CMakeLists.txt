cmake_minimum_required(VERSION 3.6.2)

project(Engine)

include(Utils)

file(GLOB_RECURSE ENGINE_INCLUDE *.hpp *.h)
file(GLOB_RECURSE ENGINE_SOURCE *.cpp *.c)

include_directories(${MODULES_ROOT})

add_library(engine ${ENGINE_INCLUDE} ${ENGINE_SOURCE})

#Add necessary libraries

if(WIN32)
	set(SDL_LIB_PATH "${EXTERNAL_ROOT}/sdl/SDL2-2.0.9_WIN/lib/x86")

	AddExternalFramework(SDL2 engine ${SDL_LIB_PATH})
	AddExternalFramework(SDL2main game ${SDL_LIB_PATH})

	AddSystemFramework(opengl32 engine)
elseif(APPLE)
	set(SDL_LIB_PATH "${EXTERNAL_ROOT}/sdl")

	AddExternalFramework(SDL2 engine ${SDL_LIB_PATH})
endif()

#Create additional IDE filters

file(GLOB_RECURSE RENDER_SOURCES render/*.hpp render/*.cpp render/*.c render/*.h)
source_group("render" FILES ${RENDER_SOURCES})

file(GLOB_RECURSE INPUT_SOURCES input/*.cpp input/*.hpp input/*.c input/*.h)
source_group("input" FILES ${INPUT_SOURCES})
