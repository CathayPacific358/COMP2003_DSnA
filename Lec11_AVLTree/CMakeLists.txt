cmake_minimum_required(VERSION 3.10)
project(DS_AVL)

set(CMAKE_CXX_STANDARD 11)

add_executable(DS_AVL main.cpp AVL.h AVL.cpp printTree.cpp)