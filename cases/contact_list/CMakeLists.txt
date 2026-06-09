cmake_minimum_required(VERSION 3.10)

project(ContactList VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src/include)

add_subdirectory(src)
