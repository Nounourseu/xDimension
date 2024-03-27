cmake_minimum_required(VERSION 3.5)
project(xDim)

include_directories(./include)
link_directories(./lib)

set(SOURCE src/main.cpp)

file(GLOB_RECURSE SOURCES "/Classes/*.cpp")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ./../bin)

add_executable(${PROJECT_NAME} ${SOURCE} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window)