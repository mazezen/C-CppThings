add_library(EmployeeManagementSystemLib STATIC
    lib/manager.cpp
    lib/manager.cpp
    lib/employee.cpp
    lib/leader.cpp
    lib/boss.cpp
)

target_include_directories(EmployeeManagementSystemLib PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

add_executable(EmployeeManagementSystemExecutable main.cpp)

target_link_libraries(EmployeeManagementSystemExecutable PRIVATE EmployeeManagementSystemLib)
