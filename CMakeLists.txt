cmake_minimum_required(VERSION 3.14)

project(sidescroller LANGUAGES CXX)

find_package(SDL3)

add_subdirectory(project)

add_executable(sidescroller project/includes/main.cpp)

target_link_libraries(sidescroller PRIVATE project)