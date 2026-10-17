cmake_minimum_required(VERSION 3.11)

project(odeint)

set(CMAKE_CXX_STANDARD 14)

add_library(odeint_library INTERFACE)

target_include_directories(odeint_library INTERFACE include)

add_executable(exe main.cpp)

# add_executable(exe test/test.cpp)

target_link_libraries(exe PRIVATE odeint_library)