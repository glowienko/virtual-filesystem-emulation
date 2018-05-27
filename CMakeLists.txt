cmake_minimum_required(VERSION 3.9)
project(kod)

set(CMAKE_CXX_STANDARD 11)

add_executable(kod main.cpp VirtualDisc.cpp VirtualDisc.h FileSystem.cpp FileSystem.h File.cpp File.h SuperBlock.cpp SuperBlock.h)