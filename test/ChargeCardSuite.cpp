//
// Created by rebecca on 12/3/20.
//

#include "gtest/gtest.h"

#include <boost/archive/text_iarchive.hpp>
#include <fstream>

#include "../project_files/banking_accounts_classes/ChargeCard.h"

class ChargeCardSuite : public testing::Test{
protected:
    virtual void SetUp(){
        ifstream iFile("../../test/files_for_testing/chargeCard.txt");
        text_iarchive ia(iFile);
        ia >> chargeCard;
        iFile.close();
    }

    ChargeCard chargeCard;
};

TEST_F(ChargeCardSuite, nonTrivialGettersTest){
    //testing getLimits()
    auto limits = chargeCard.getLimits();
    ASSERT_TRUE(limits.first == 5000 && limits.second == 10000);
    //testing getNumberAndType()
    auto numberAndType = chargeCard.getNumberAndType();
    ASSERT_TRUE(numberAndType.first == "0529 3323 7340 9918" && numberAndType.second == CardType::debit);
    //testing getAssociatedBankingAccount()
    auto bankingAccount = chargeCard.getAssociatedBankingAccount();
    ASSERT_TRUE(bankingAccount.first == "Eleonora Frangetti" && bankingAccount.second == "IT31M02067215321000000009234");
}

TEST_F(ChargeCardSuite, setLimitTest){
    //verify preconditions
    ASSERT_EQ(chargeCard.getLimits().first,5000);

    //not acceptable limit
    EXPECT_FALSE(chargeCard.setLimit(20000));
    ASSERT_EQ(chargeCard.getLimits().first,5000);

    //acceptable limit
    EXPECT_TRUE(chargeCard.setLimit(7000));
    ASSERT_EQ(chargeCard.getLimits().first,7000);
}

TEST_F(ChargeCardSuite, getLatestTransactionTest){
    //testing on existing chargeCard
    ASSERT_EQ(chargeCard.getLatestTransaction(), "12/02/20 09:44:13");
    //testing on new empty chargeCard
    ChargeCard emptyChargeCard;
    EXPECT_EQ(emptyChargeCard.getLatestTransaction(),"no transactions");
}

TEST_F(ChargeCardSuite, returnSelectedTest){
    //requesting all transactions
    auto list = chargeCard.returnSelected(RequestedTransactions::all);
    EXPECT_EQ(list.size(),8);
    auto firstCT = *list.begin();
    EXPECT_EQ(firstCT->getDate(),"09/28/20 09:44:13");
    EXPECT_EQ(firstCT->getLocation(),"giometti cinema, cambi bisenzio");
    auto lastCT = list[7]; //last element of the list
    EXPECT_EQ(lastCT->getDate(),chargeCard.getLatestTransaction());

    //filtering by date
    list = chargeCard.returnSelected(RequestedTransactions::specificDate,"11/18/20");
    ASSERT_EQ(list.size(),1);
    ASSERT_EQ(list[0]->getAmount(),-3);
    EXPECT_TRUE(list[0]->isProcessed());
    EXPECT_TRUE(list[0]->isSpecificCategory("transports"));

    list = chargeCard.returnSelected(RequestedTransactions::specificDate,"09/27/20");
    EXPECT_TRUE(list.empty());

    //filtering by category
    list = chargeCard.returnSelected(RequestedTransactions::specificCategory,"restaurants");
    ASSERT_EQ(list.size(),2);
    list = chargeCard.returnSelected(RequestedTransactions::specificCategory,"health");
    ASSERT_EQ(list.size(),1);
    list = chargeCard.returnSelected(RequestedTransactions::specificCategory,"fuel");
    EXPECT_TRUE(list.empty());
}


