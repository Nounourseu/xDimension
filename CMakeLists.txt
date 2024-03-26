cmake_minimum_required(VERSION 3.0)
project(xDim)

include_directories(./include)
link_directories(./lib)

set(SOURCE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window)