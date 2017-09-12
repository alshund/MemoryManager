cmake_minimum_required(VERSION 3.8)
project(MemoryManager)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c mmemory.h mmemory.c memory_area.h memory_area.c mmemory.c)
add_executable(MemoryManager ${SOURCE_FILES})