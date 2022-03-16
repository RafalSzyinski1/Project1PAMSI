cmake_minimum_required(VERSION 3.16)
project(PAMSI)

set(APP_DIR ${CMAKE_SOURCE_DIR}/app)
set(CODE_DIR ${APP_DIR}/code)

file(GLOB_RECURSE SOURCES ${CODE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${APP_DIR}/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CODE_DIR})