cmake_minimum_required(VERSION 3.6.2)

project(Game)

add_executable(game main.cpp)

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

if(WIN32)
	include_directories(${SDL_INCLUDE_PATH})
	include_directories(${SDL_NET_INCLUDE_PATH})
	
	AddExternalFramework(SDL2 game ${SDL_LIB_PATH})
	AddExternalFramework(SDL2main game ${SDL_LIB_PATH})
	AddExternalFramework(SDL2_net game ${SDL_NET_LIB_PATH})
	
	#https://docs.microsoft.com/en-us/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box?view=vs-2017
	add_custom_command(TARGET game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SDL_LIB_PATH}/SDL2.dll $(OutDir))
elseif(APPLE)
	AddExternalFramework(SDL2 game ${SDL_LIB_PATH})
	AddExternalFramework(SDL2_net game ${SDL_NET_LIB_PATH})
else()
	message(FATAL_ERROR "Unsupported platform")
endif()