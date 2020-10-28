cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES WelcomePage.cpp WelcomePage.h utilityFunctions.cpp utilityFunctions.h
        AccessManagerView.cpp AccessManagerView.h PersonalAreaView.cpp PersonalAreaView.h Account.h
        InputManager.cpp InputManager.h AccountsManagerView.cpp AccountsManagerView.h SmartLockView.cpp
        SmartLockView.h RemindersManager.cpp RemindersManager.h Reminder.cpp Reminder.h Alert.cpp
        Alert.h AlertsManager.cpp AlertsManager.h Interface.cpp Interface.h Profile.cpp
        Profile.h SecurityManagerView.cpp SecurityManagerView.h ProfileManagerView.cpp ProfileManagerView.h
        Transaction.cpp Transaction.h WireTransfer.cpp WireTransfer.h CardTransaction.cpp CardTransaction.h
        Deposit.cpp Deposit.h PhoneRecharge.cpp PhoneRecharge.h BankBranch.cpp BankBranch.h DateSetter.cpp DateSetter.h SmartLock.cpp SmartLock.h AccessManager.cpp AccessManager.h Account.cpp SecurityManager.cpp SecurityManager.h)

add_library(core ${SOURCE_FILES})
