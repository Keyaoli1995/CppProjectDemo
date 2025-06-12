cmake_minimum_required(VERSION 3.10)
project(MultyThread)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置可执行文件输出到 ./build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

# 设置动态库输出到 ./build/lib/
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

# 设置静态库输出到 ./build/lib/
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

# 确保目录存在
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})


add_executable(sample1 src/sample1.cpp)
file(GLOB SRC_LIST ${PROJECT_SOURCE_DIR}/src/cmn/*.cpp)
add_executable(sample2 src/sample2.cpp ${SRC_LIST})
target_include_directories(sample2
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)