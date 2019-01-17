cmake_minimum_required(VERSION 3.6.2)

project(Engine)

file(GLOB ENGINE_INCLUDE *.hpp)
file(GLOB ENGINE_SOURCE *.cpp)

add_library(engine ${ENGINE_INCLUDE} ${ENGINE_SOURCE})