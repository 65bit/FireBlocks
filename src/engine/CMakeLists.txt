cmake_minimum_required(VERSION 3.6.2)

project(Engine)

file(GLOB ENGINE_INCLUDE *.hpp)
file(GLOB ENGINE_SOURCE *.cpp)

file(GLOB_RECURSE RENDER_SOURCES renderer/*.cpp renderer/*.hpp)

add_library(engine ${ENGINE_INCLUDE} ${ENGINE_SOURCE} ${RENDER_SOURCES} )
include_directories(${CMAKE_SOURCE_DIR}/src)

if(WIN32)
source_group("renderer" FILES ${RENDER_SOURCES})
endif()