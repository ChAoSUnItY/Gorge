cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)

project(Gorge)

add_subdirectory(fmt EXCLUDE_FROM_ALL)

add_executable(Gorge src/main.cpp include/report.hpp)
target_compile_features(Gorge PUBLIC cxx_std_17)
target_link_libraries(Gorge fmt-header-only)
