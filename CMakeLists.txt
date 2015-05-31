cmake_minimum_required(VERSION 2.8)
project(ski-challenge)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)

if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  message(ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


set(SRC 
    mountain.cpp
    solver.cpp
)

add_library(skiSolver ${SRC})

add_executable(skiChallenge main.cpp)
target_link_libraries(skiChallenge skiSolver)