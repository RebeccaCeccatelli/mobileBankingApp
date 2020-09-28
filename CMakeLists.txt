cmake_minimum_required(VERSION 3.17)
project(mobile_banking_app)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES WelcomePage.cpp WelcomePage.h utilityFunctions.cpp utilityFunctions.h
        AccessManager.cpp AccessManager.h PersonalArea.cpp PersonalArea.h Account.h
        InputManager.cpp InputManager.h AccountsManager.cpp AccountsManager.h SmartLock.cpp SmartLock.h test/runAllTests.cpp)
add_executable(mobile_banking_app main.cpp  )

add_library(core ${SOURCE_FILES})
target_link_libraries(mobile_banking_app core)