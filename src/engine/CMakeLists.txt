cmake_minimum_required(VERSION 3.6.2)

project(Engine)

file(GLOB_RECURSE ENGINE_INCLUDE *.hpp *.h)
file(GLOB_RECURSE ENGINE_SOURCE *.cpp *.c)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(engine ${ENGINE_INCLUDE} ${ENGINE_SOURCE})

#Create additional IDE filters

file(GLOB_RECURSE RENDER_SOURCES render/*.hpp render/*.cpp render/*.c render/*.h)
source_group("render" FILES ${RENDER_SOURCES})

file(GLOB_RECURSE INPUT_SOURCES input/*.cpp input/*.hpp input/*.c input/*.h)
source_group("input" FILES ${INPUT_SOURCES})
