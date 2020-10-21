cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES WelcomePage.cpp WelcomePage.h utilityFunctions.cpp utilityFunctions.h
        AccessManager.cpp AccessManager.h PersonalArea.cpp PersonalArea.h Account.h
        InputManager.cpp InputManager.h AccountsManager.cpp AccountsManager.h SmartLock.cpp
        SmartLock.h RemindersManager.cpp RemindersManager.h Reminder.cpp Reminder.h Alert.cpp
        Alert.h AlertsManager.cpp AlertsManager.h Interface.cpp Interface.h Profile.cpp
        Profile.h SecurityManager.cpp SecurityManager.h ProfileManager.cpp ProfileManager.h
        Transaction.cpp Transaction.h WireTransfer.cpp WireTransfer.h CardTransaction.cpp CardTransaction.h
        Deposit.cpp Deposit.h PhoneRecharge.cpp PhoneRecharge.h BankBranch.cpp BankBranch.h DateSetter.cpp DateSetter.h)

add_library(core ${SOURCE_FILES})
