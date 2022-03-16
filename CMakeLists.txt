cmake_minimum_required(VERSION 3.16)
project(PAMSI)

set(CODE_DIR ${CMAKE_SOURCE_DIR}/code)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true ${CODE_DIR}/*.cpp)
include_directories(${CODE_DIR})

add_subdirectory(lib/googletest)
add_subdirectory(test)

add_executable(${PROJECT_NAME} ${SOURCES})
add_library(PROJECT_LIB STATIC ${SOURCES})
