# stop if cmake version below 3.5
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and supported languages
project(ProjectTopic2 CXX)

# example how to set c++ compiler flags for GNU
#if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unknown-pragmas -Wno-sign-compare -Woverloaded-virtual -Wwrite-strings -Wno-unused -std=c++17")
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
#endif()

add_compile_definitions(SOURCE_PATH=${CMAKE_CURRENT_SOURCE_DIR})

add_library(project_topic_2 ProjectTopic2.cpp)

add_executable(project_topic_2.out ProjectTopic2.cpp)
