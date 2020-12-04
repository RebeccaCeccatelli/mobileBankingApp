//
// Created by rebecca on 12/3/20.
//

#include <string>

#include "gtest/gtest.h"

#include "../project_files/banking_accounts_classes/Transaction.h"

using namespace std;

class TransactionSuite : public testing::Test {
protected:
    Transaction transaction1{50};
    Transaction transaction2{30,"wire transfer","restaurants",true};
};

TEST_F(TransactionSuite, constructorTest){

    //testing constructor passing only one argument
    EXPECT_EQ(transaction1.getAmount(),50);
    EXPECT_EQ(transaction1.getDescription(),"not specified");
    EXPECT_EQ(transaction1.getCategory(),"general");
    EXPECT_FALSE(transaction1.isProcessed());

    //testing constructor passing multiple arguments
    EXPECT_EQ(transaction2.getAmount(),30);
    EXPECT_EQ(transaction2.getDescription(),"wire transfer");
    EXPECT_FALSE(transaction2.getCategory() == "general");
    EXPECT_TRUE(transaction2.isProcessed());
}

TEST_F(TransactionSuite, isSpecificCategoryTest){

    EXPECT_FALSE(transaction2.isSpecificCategory("food"));
    EXPECT_TRUE(transaction2.isSpecificCategory("restaurants"));
}

TEST_F(TransactionSuite, isSpecificDateTest){
    string wrongDate = "02/24/16";
    EXPECT_FALSE(transaction1.isSpecificDate(wrongDate));

    DateSetter dateSetter;
    dateSetter.setDate();
    EXPECT_TRUE(transaction1.isSpecificDate(dateSetter.getDate().substr(0,8)));
}