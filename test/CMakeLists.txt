cmake_minimum_required(VERSION 3.5)

add_subdirectory(lib/googletest-master)

set(TEST_SOURCE_FILES runAllTests.cpp SmartLockSuite.cpp AccessManagerSuite.cpp AccountSuite.cpp SecurityManagerSuite.cpp AlertSuite.cpp AlertsManagerSuite.cpp ReminderSuite.cpp RemindersManagerSuite.cpp CompareSuite.cpp TransactionSuite.cpp WireTransferSuite.cpp PhoneRechargeSuite.cpp ChargeCardSuite.cpp)
add_executable(runBankingAppTests ${TEST_SOURCE_FILES})

target_link_libraries(runBankingAppTests gtest gtest_main core)
