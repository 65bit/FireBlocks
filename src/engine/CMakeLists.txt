cmake_minimum_required(VERSION 3.6.2)

project(Engine)

file(GLOB_RECURSE ENGINE_INCLUDE *.hpp)
file(GLOB_RECURSE ENGINE_SOURCE *.cpp)
file(GLOB_RECURSE RENDER_SOURCES render/*.cpp render/*.hpp)

set (GL_CORE_SRCS ${CMAKE_SOURCE_DIR}/src/engine/render/opengl_renderer/gl_core_3_2.c)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(engine ${ENGINE_INCLUDE} ${ENGINE_SOURCE} ${GL_CORE_SRCS})

source_group("renderer" FILES ${RENDER_SOURCES})
