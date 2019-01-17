cmake_minimum_required(VERSION 3.6.2)

project(Game)

add_executable(game main.cpp)

include(Utils)

include_directories(${CMAKE_SOURCE_DIR}/src)

if(WIN32)
	include_directories(${SDL_INCLUDE_PATH})
	include_directories(${SDL_NET_INCLUDE_PATH})

	AddExternalFramework(SDL2 game ${SDL_LIB_PATH})
	AddExternalFramework(SDL2main game ${SDL_LIB_PATH})
	AddExternalFramework(SDL2_net game ${SDL_NET_LIB_PATH})

	target_link_libraries(game opengl32)

	#https://docs.microsoft.com/en-us/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box?view=vs-2017
	add_custom_command(TARGET game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SDL_LIB_PATH}/SDL2.dll $(OutDir))
elseif(APPLE)
	AddExternalFramework(SDL2 game ${SDL_LIB_PATH})
	AddExternalFramework(SDL2_net game ${SDL_NET_LIB_PATH})
else()
	message(FATAL_ERROR "Unsupported platform")
endif()

target_link_libraries(game engine)