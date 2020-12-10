cmake_minimum_required( VERSION 3.10 )
project(AST)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON)


INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp ast_inter.cpp)