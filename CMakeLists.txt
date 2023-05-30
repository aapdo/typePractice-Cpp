cmake_minimum_required(VERSION 3.25)
project(project)

option(CURL_STATIC_LINKING "Set to ON to build libcurl with static linking."  OFF)

if(CURL_STATIC_LINKING)
    message("-DCURL_STATICLIB [added]")
    add_definitions(-DCURL_STATICLIB)
endif()

add_definitions(-DJSON_USE_IMPLICIT_CONVERSIONS=0)

# SET(CURL_MIN_VERSION "7.61.0")
find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIRS})

message("Using compiler ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

set(CMAKE_CXX_STANDARD 17 "-fexec-charset=CP949")
include_directories(include/openai)
#add_executable(${CURL_LIBRARIES})
#target_link_libraries(${CURL_LIBRARIES})
add_executable(project main.cpp scriptManage/manager/ScriptManager.h scriptManage/manager/ScriptManager.cpp lib/FileControllInterface.h lib/FileControllInterface.cpp scriptManage/manager/ParagraphManager.cpp scriptManage/manager/ParagraphManager.h service/Practice/WordSentenceTypePractice.cpp service/Practice/WordSentenceTypePractice.h service/record/Recorder.h service/record/Recorder.cpp lib/utils.cpp service/Practice/ParagraphTypePractice.cpp service/Practice.h service/Practice.cpp user/User.cpp service/record/UserService.cpp game/Maze.h game/Maze.cpp game/Game.cpp)
target_link_libraries(project CURL::libcurl)
