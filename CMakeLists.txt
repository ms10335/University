cmake_minimum_required(VERSION 3.13)
project(University)

set(SRC 
    checkPesel.cpp 
    student.cpp)

set(CMAKE_CXX_STANDARD 17)
set (FLAGS -Wall -Wextra -Wpedantic -Wconversion )

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
