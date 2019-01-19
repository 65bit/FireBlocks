cmake_minimum_required(VERSION 3.6.2)

project(Game)

add_executable(game main.cpp)

include_directories(${MODULES_ROOT})

if(WIN32)
	#https://docs.microsoft.com/en-us/visualstudio/ide/reference/pre-build-event-post-build-event-command-line-dialog-box?view=vs-2017
	add_custom_command(TARGET game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SDL_LIB_PATH}/SDL2.dll $(OutDir))
endif()

target_link_libraries(game engine)