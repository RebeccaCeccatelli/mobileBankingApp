cmake_minimum_required(VERSION 3.17)
project(mobile_banking_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(mobile_banking_app main.cpp WelcomePage.cpp WelcomePage.h
        utilityFunctions.cpp utilityFunctions.h AccessManager.cpp AccessManager.h PersonalArea.cpp PersonalArea.h
        Account.h InputManager.cpp InputManager.h SmartLock.cpp SmartLock.h AccountsManager.cpp AccountsManager.h)