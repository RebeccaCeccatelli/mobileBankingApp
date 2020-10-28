cmake_minimum_required(VERSION 3.5)

add_subdirectory(lib/googletest-master)

set(TEST_SOURCE_FILES runAllTests.cpp AccessManagerSuite.cpp SmartLockSuite.cpp AccountSuite.cpp SecurityManagerSuite.cpp)
add_executable(runBankingAppTests ${TEST_SOURCE_FILES})

target_link_libraries(runBankingAppTests gtest gtest_main gmock gmock_main core)
