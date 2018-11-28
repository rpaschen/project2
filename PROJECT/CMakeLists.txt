cmake_minimum_required(VERSION 3.12)
project(PROJECT)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROJECT main.cpp auDiskTool.cpp auDiskTool.h Configuration.cpp Configuration.h Tool.cpp Tool.h CommandLine.cpp CommandLine.h Report.cpp Report.h)