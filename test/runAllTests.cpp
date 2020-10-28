//
// Created by Rebecca on 28/09/2020.
//

#include <iostream>
#include "gtest/gtest.h"

using namespace std;

int main(){
    cout << "Testing project files..." << endl;

    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
