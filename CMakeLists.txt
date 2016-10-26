cmake_minimum_required(VERSION 3.6)
project(TSP2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Greedy.h Greedy.cpp SAalg.cpp SAalg.h util.h util.cpp twoopt.cpp twoopt.h irpbn.h irpbn.cpp grtdm.cpp grtdm.h)
add_executable(TSP2d ${SOURCE_FILES} Greedy.h Greedy.cpp)