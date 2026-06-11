# brew install googletest
# 查找 GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 创建测试目标
add_executable(test01 test01.cpp)

# 链接库和 GTest 到测试目标
target_link_libraries(test01 PRIVATE EmployeeManagementSystemLib ${GTEST_LIBRARIES})
