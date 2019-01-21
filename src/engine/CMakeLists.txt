cmake_minimum_required(VERSION 3.6.2)

project(Engine)

include(Utils)

file(GLOB_RECURSE ENGINE_INCLUDE *.hpp *.h)
file(GLOB_RECURSE ENGINE_SOURCE *.cpp *.c)

add_library(engine ${ENGINE_INCLUDE} ${ENGINE_SOURCE})

#Add necessary libraries

if(WIN32)
	include_directories("${EXTERNAL_ROOT}/sdl/SDL2-2.0.9_WIN/include")
	
	set(SDL_LIB_PATH "${EXTERNAL_ROOT}/sdl/SDL2-2.0.9_WIN/lib/x86")
	
	AddExternalFramework(SDL2 engine ${SDL_LIB_PATH})
	AddExternalFramework(SDL2main engine ${SDL_LIB_PATH})

	target_link_libraries(engine opengl32)
elseif(APPLE)
	set(SDL_LIB_PATH "${EXTERNAL_ROOT}/sdl")

	AddExternalFramework(SDL2 engine ${SDL_LIB_PATH})
endif()

#Adding additional Includes

include_directories(${MODULES_ROOT})
include_directories("${EXTERNAL_ROOT}/glm")

#Create additional IDE filters

file(GLOB_RECURSE COMPONENT_SOURCES component/*.cpp component/*.hpp component/*.c component/*.h)
source_group("component" FILES ${COMPONENT_SOURCES})

file(GLOB_RECURSE GAMEPLAY_SOURCES gameplay/*.hpp gameplay/*.cpp gameplay/*.c gameplay/*.h)
source_group("gameplay" FILES ${GAMEPLAY_SOURCES})

file(GLOB_RECURSE MATH_SOURCES math/*.hpp math/*.cpp math/*.c math/*.h)
source_group("math" FILES ${MATH_SOURCES})

file(GLOB_RECURSE RENDER_SOURCES render/*.hpp render/*.cpp render/*.c render/*.h)
source_group("render" FILES ${RENDER_SOURCES})
