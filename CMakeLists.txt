cmake_minimum_required(VERSION 2.8.3)
project(yaml)
add_compile_options(-std=c++11)
set(CMAKE_BUILD_TYPE Release)#RelWithDebInfoset(CMAKE_BUILD_TYPE Release)
link_directories(/usr/local/lib)
include_directories(/usr/local/include/yaml-cpp)

add_executable (test ./yaml_demo.cpp )
target_link_libraries(test yaml-cpp)
