cmake_minimum_required(VERSION 3.17)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MY_DATA_DIR ${CMAKE_SOURCE_DIR}/data)

set(SRC_LIST cpu.cpp disk.cpp gpu.cpp kdb.cpp main.cpp ram.cpp)

set(INCLUDE_LIST ${MY_INCLUDE_DIR}/cpu.h ${MY_INCLUDE_DIR}/disk.h ${MY_INCLUDE_DIR}/gpu.h ${MY_INCLUDE_DIR}/kdb.h ${MY_INCLUDE_DIR}/ram.h ${MY_INCLUDE_DIR}/head.h)

set(DATA_LIST ${MY_DATA_DIR}/data.txt)

add_executable(${PROJECT_NAME} ${SRC_LIST} ${INCLUDE_LIST} ${DATA_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIR})