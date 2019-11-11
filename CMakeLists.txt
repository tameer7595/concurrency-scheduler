cmake_minimum_required(VERSION 3.14)
project(Scheduler)

set(CMAKE_CXX_STANDARD 98)

add_executable(Scheduler main.cpp scheduler.cpp scheduler.h itask.h itask.cpp)