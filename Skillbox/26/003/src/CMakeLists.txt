cmake_minimum_required(VERSION 3.23)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(003 main.cpp)

target_include_directories(003 PUBLIC ${MY_INCLUDE})