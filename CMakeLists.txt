cmake_minimum_required(VERSION 3.14)

project(sidescroller)

enable_language(C)

find_package(SDL3)

add_subdirectory(project)
add_subdirectory(game)