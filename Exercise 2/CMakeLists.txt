cmake_minimum_required(VERSION 3.22)
project(Exercise_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exercise_2 main.cpp collision_detection.hpp collision_detection.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ../SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics REQUIRED)

include_directories(../SFML/include)
target_link_libraries(Exercise_2 sfml-system sfml-window sfml-graphics)