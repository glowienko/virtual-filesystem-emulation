cmake_minimum_required(VERSION 3.9)
project(kod)

set(CMAKE_CXX_STANDARD 11)

add_executable(kod main.cpp filesystem/disc/VirtualDisc.cpp filesystem/disc/VirtualDisc.h filesystem/FileSystem.cpp filesystem/FileSystem.h file/File.cpp file/File.h filesystem/disc/parts/SuperBlock.cpp filesystem/disc/parts/SuperBlock.h filesystem/disc/parts/FileDescriptor.cpp filesystem/disc/parts/FileDescriptor.h filesystem/disc/parts/DataBlock.cpp filesystem/disc/parts/DataBlock.h)