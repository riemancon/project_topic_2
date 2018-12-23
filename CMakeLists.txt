cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(ProjectTopic2 CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_compile_definitions(SOURCE_PATH=${CMAKE_CURRENT_SOURCE_DIR})

add_library(project_topic_2 ProjectTopic2.cpp)

add_executable(project_topic_2.out ProjectTopic2.cpp)
