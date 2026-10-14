cmake_minimum_required(VERSION 3.16)
project(cpp_homework_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(task1 task_1/main.cpp)
add_executable(task2 task_2/main.cpp)
add_executable(task3 task_3/main.cpp)
add_executable(task4 task_4/main.cpp)

foreach(target task1 task2 task3 task4)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
  elseif(MSVC)
    target_compile_options(${target} PRIVATE /W4)
  endif()
endforeach()
