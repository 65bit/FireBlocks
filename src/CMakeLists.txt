cmake_minimum_required(VERSION 3.6.2)

project(Game)

add_executable(game main.cpp)

if(WIN32)

elseif(APPLE)

macro(AddExternalFramework fwname appname libpath)
    find_library(FRAMEWORK_${fwname}
        NAMES ${fwname}
        PATHS ${libpath} 
        NO_DEFAULT_PATH)
    if( ${FRAMEWORK_${fwname}} STREQUAL FRAMEWORK_${fwname}-NOTFOUND)
        MESSAGE(ERROR ": Framework ${fwname} not found: ${FRAMEWORK_${fwname}}")
    else()
        TARGET_LINK_LIBRARIES(${appname} ${FRAMEWORK_${fwname}})
        MESSAGE(STATUS "Framework ${fwname} found at ${FRAMEWORK_${fwname}}")
    endif()
endmacro(AddExternalFramework)

	set(FRAMEWORK_DIR "${CMAKE_SOURCE_DIR}/external/sdl/")

	AddExternalFramework(SDL2 game ${FRAMEWORK_DIR})
	AddExternalFramework(SDL2_net game ${FRAMEWORK_DIR})
else()
	message(FATAL_ERROR "Undefined platform")
endif()