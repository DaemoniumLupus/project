cmake_minimum_required(VERSION 3.23)

add_executable(001 main.cpp)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(001 PUBLIC ${MY_INCLUDE})