cmake_minimum_required(VERSION 3.10)

project(EmployeeManagementSystem VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src/include)

# 生成 compile_commands.json 供 VSCode IntelliSense 使用
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(tests)
