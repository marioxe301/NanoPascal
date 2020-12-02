cmake_minimum_required( VERSION 3.10 )
project(Lexer)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON)

add_custom_command(
    OUTPUT lexer.cpp
    COMMAND fa2lexer --hdr tokens.h --src lexer.cpp --tpl ${PROJECT_SOURCE_DIR}/DFA/template.h
    MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/DFA/template.h
    DEPENDS ${PROJECT_SOURCE_DIR}/DFA/start.jff
    DEPENDS ${PROJECT_SOURCE_DIR}/DFA/identifiers.jff
    DEPENDS ${PROJECT_SOURCE_DIR}/DFA/constants.jff
    DEPENDS ${PROJECT_SOURCE_DIR}/DFA/comments.jff
    DEPENDS ${PROJECT_SOURCE_DIR}/DFA/operators.jff
)

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})

# Solo seria ejecutable para probar el lexer, pero no se va usar
add_executable(${PROJECT_NAME} main.cpp lexer.cpp)