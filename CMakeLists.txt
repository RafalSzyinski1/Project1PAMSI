cmake_minimum_required(VERSION 3.16)
project(PAMSI)

set(CODE_DIR ${CMAKE_SOURCE_DIR}/code)

file(GLOB_RECURSE SOURCES ${CODE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CODE_DIR})