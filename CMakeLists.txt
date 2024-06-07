cmake_minimum_required(VERSION 3.28)
project(c100)

set(CMAKE_CXX_STANDARD 17)

add_executable(c100 src/main.cpp
        src/Lexer.cpp
        src/Parser.cpp
        src/CodeGen.cpp
        src/AstNode.cpp
        src/PrintVisitor.cpp)
