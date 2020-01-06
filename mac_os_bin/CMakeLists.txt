cmake_minimum_required(VERSION 3.10)

set(LIBRARY_NAME TestLeetCode)
project(${LIBRARY_NAME})

set(CMAKE_CXX_STANDARD 11)

# 搜集源码文件
file(GLOB SRC ../src/QuickSort.cpp)

set(SOURCE_FILES ${SRC})

add_executable(${LIBRARY_NAME} ${SOURCE_FILES})

target_link_libraries(${LIBRARY_NAME})
