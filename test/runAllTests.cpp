//
// Created by Rebecca on 28/09/2020.
//

#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

int main(){
    cout << "Se mi stampa funziona." << endl;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
