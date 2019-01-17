cmake_minimum_required(VERSION 3.6.2)

project(Engine)

file(GLOB_RECURSE ENGINE_INCLUDE *.hpp)
file(GLOB_RECURSE ENGINE_SOURCE *.cpp)
file(GLOB_RECURSE RENDER_SOURCES render/*.cpp render/*.hpp)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(engine ${ENGINE_INCLUDE} ${ENGINE_SOURCE})

source_group("renderer" FILES ${RENDER_SOURCES})
