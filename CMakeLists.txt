cmake_minimum_required(VERSION 3.17)
project(mobile_banking_app)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(test)

set(SOURCE_FILES WelcomePage.cpp WelcomePage.h utilityFunctions.cpp utilityFunctions.h
        AccessManager.cpp AccessManager.h PersonalArea.cpp PersonalArea.h Account.h
        InputManager.cpp InputManager.h AccountsManager.cpp AccountsManager.h SmartLock.cpp
        SmartLock.h RemindersManager.cpp RemindersManager.h Reminder.cpp Reminder.h Alert.cpp
        Alert.h AlertsManager.cpp AlertsManager.h Interface.cpp Interface.h Profile.cpp
        Profile.h SecurityManager.cpp SecurityManager.h ProfileManager.cpp ProfileManager.h Transaction.cpp Transaction.h WireTransfer.cpp WireTransfer.h CardTransaction.cpp CardTransaction.h Deposit.cpp Deposit.h PhoneRecharge.cpp PhoneRecharge.h)
add_executable(mobile_banking_app main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(mobile_banking_app core)