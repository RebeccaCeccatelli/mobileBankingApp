cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES login_classes/WelcomePage.cpp login_classes/WelcomePage.h utilityFunctions.cpp utilityFunctions.h
        login_classes/AccessManagerView.cpp login_classes/AccessManagerView.h login_classes/PersonalAreaView.cpp login_classes/PersonalAreaView.h login_classes/Account.h
        InputManager.cpp InputManager.h login_classes/AccountsManagerView.cpp login_classes/AccountsManagerView.h login_classes/SmartLockView.cpp
        login_classes/SmartLockView.h reminder_classes/RemindersManagerView.cpp reminder_classes/RemindersManagerView.h reminder_classes/Reminder.cpp reminder_classes/Reminder.h alert_classes/Alert.cpp
        alert_classes/Alert.h alert_classes/AlertsManagerView.cpp alert_classes/AlertsManagerView.h Interface.cpp Interface.h profile_classes/ProfileView.cpp
        profile_classes/ProfileView.h profile_classes/SecurityManagerView.cpp profile_classes/SecurityManagerView.h profile_classes/ProfileManagerView.cpp profile_classes/ProfileManagerView.h
        Transaction.cpp Transaction.h WireTransfer.cpp WireTransfer.h CardTransaction.cpp CardTransaction.h
        Deposit.cpp Deposit.h PhoneRecharge.cpp PhoneRecharge.h profile_classes/BankBranchView.cpp profile_classes/BankBranchView.h
        DateSetter.cpp DateSetter.h login_classes/SmartLock.cpp login_classes/SmartLock.h login_classes/AccessManager.cpp login_classes/AccessManager.h login_classes/Account.cpp
        profile_classes/SecurityManager.cpp profile_classes/SecurityManager.h profile_classes/Profile.cpp profile_classes/Profile.h alert_classes/AlertsManager.cpp alert_classes/AlertsManager.h reminder_classes/RemindersManager.cpp reminder_classes/RemindersManager.h)

add_library(core ${SOURCE_FILES})
