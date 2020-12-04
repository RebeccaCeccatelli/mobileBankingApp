//
// Created by rebecca on 12/3/20.
//

#include "gtest/gtest.h"

#include <boost/archive/text_iarchive.hpp>
#include <fstream>

#include "../project_files/banking_accounts_classes/BankingAccount.h"

class BankingAccountSuite : public testing::Test{
protected:
    virtual void SetUp(){
        ifstream iFile("/home/rebecca/CLionProjects/Laboratorio_di_programmazione/mobile_banking_app/test/files_for_testing/bankingAccount.txt");
        text_iarchive ia(iFile);
        ia >> bankingAccount;
        iFile.close();
    }

    BankingAccount bankingAccount;
};

TEST_F(BankingAccountSuite, getDetailedInformationsTest){
    auto infos = bankingAccount.getDetailedInformations();

    ASSERT_EQ(get<0>(infos), "Eleonora Frangetti");
    ASSERT_EQ(get<1>(infos),"08/22/20 12:20:54");
    ASSERT_EQ(get<2>(infos),2);
    ASSERT_EQ(get<3>(infos),"12/02/20 10:54:13");
}

TEST_F(BankingAccountSuite, getChargeCardsListTest){
    map<string,ChargeCard>* list = bankingAccount.getChargeCardsList();

    EXPECT_EQ(list->size(),2);
    string firstCardNumber = list->begin()->second.getNumberAndType().first;
    string secondCardNumber = list->crbegin()->second.getNumberAndType().first;
    EXPECT_EQ(firstCardNumber, "0529 3323 7340 9918");
    EXPECT_EQ(secondCardNumber, "3124 5611 7823 0098");
}

TEST_F(BankingAccountSuite, isLowDepositTest){
    //verify preconditions
    EXPECT_TRUE(bankingAccount.getDeposit() == 10000);

    bankingAccount.setDeposit(3000);
    EXPECT_FALSE(bankingAccount.isLowDeposit());

    bankingAccount.setDeposit(50);
    EXPECT_TRUE(bankingAccount.isLowDeposit());
    bankingAccount.setDeposit(20);
    EXPECT_TRUE(bankingAccount.isLowDeposit());
}

TEST_F(BankingAccountSuite, returnSelectedTest){
    //requesting all transactions
    auto list = bankingAccount.returnSelected(RequestedTransactions::all);

    EXPECT_EQ(list.size(),24);
    auto firstTransaction = *list.begin();
    EXPECT_EQ(firstTransaction->getAmount(),-100);
    EXPECT_EQ(firstTransaction->getDate(),"07/29/20 12:57:23");
    EXPECT_EQ(firstTransaction->getDescription(),"card transaction");
    auto casualTransaction = list[19];
    EXPECT_EQ(casualTransaction->getAmount(),800);
    EXPECT_EQ(casualTransaction->getDate(),"12/01/20 13:12:44");
    EXPECT_EQ(casualTransaction->getDescription(),"wire transfer");

    //filtering by date
    list = bankingAccount.returnSelected(RequestedTransactions::specificDate,"11/18/20");
    EXPECT_EQ(list.size(),2);
    EXPECT_EQ(list[0]->getAmount(),-160);
    EXPECT_EQ(list[1]->getAmount(),-3);

    list = bankingAccount.returnSelected(RequestedTransactions::specificDate,"12/01/20");
    EXPECT_EQ(list.size(),4);
    int dailyReport = list[0]->getAmount()+list[1]->getAmount()+list[2]->getAmount()+list[3]->getAmount();
    EXPECT_EQ(dailyReport,935);

    list = bankingAccount.returnSelected(RequestedTransactions::specificDate,"12/04/20");
    EXPECT_TRUE(list.empty());

    //filtering by category
    list = bankingAccount.returnSelected(RequestedTransactions::specificCategory,"general");
    EXPECT_EQ(list.size(),9);
    list = bankingAccount.returnSelected(RequestedTransactions::specificCategory,"fuel");
    EXPECT_EQ(list.size(),1);

}

TEST_F(BankingAccountSuite, createPhoneRechargeTest){
    //verify preconditions
    auto numberOfTransactions = bankingAccount.returnSelected(RequestedTransactions::all).size();
    EXPECT_EQ(numberOfTransactions,24);

    //create phone recharge
    auto userInformations = make_tuple("wind","3357561324",-15);
    bool accepted = bankingAccount.createPhoneRecharge(userInformations);

    //check deposit, testing indirectly private method subtractAmount()
    EXPECT_TRUE(accepted);
    ASSERT_EQ(bankingAccount.getDeposit(),9985);

    //check if phone recharge is added to transactions'list
    auto list = bankingAccount.returnSelected(RequestedTransactions::all);
    numberOfTransactions = list.size();
    EXPECT_EQ(numberOfTransactions,25);

    EXPECT_TRUE(list[24]->getAmount() == -15);
    EXPECT_TRUE(list[24]->getDescription() == "phone recharge");
    EXPECT_FALSE(list[24]->isProcessed());

    //phone recharge negated
    accepted = bankingAccount.createPhoneRecharge(make_tuple("iliad","34756235466",-20000));
    EXPECT_FALSE(accepted);
    EXPECT_EQ(bankingAccount.getDeposit(),9985);
}

TEST_F(BankingAccountSuite, createWireTransferTest){
    //verify preconditions
    auto numberOfTransactions = bankingAccount.returnSelected(RequestedTransactions::all).size();
    EXPECT_EQ(numberOfTransactions,24);

    //create wire transfer
    auto userInformations = make_tuple("IT31M02067215321000000003333","Jack Jones","counseling service",-2000);
    bool accepted = bankingAccount.createWireTransfer(userInformations);

    //check deposit, testing indirectly private method subtractAmount() with commissions
    EXPECT_TRUE(accepted);
    EXPECT_NE(bankingAccount.getDeposit(),8000);
    EXPECT_EQ(bankingAccount.getDeposit(),7998);

    //check if wire transfer is added to transactions'list
    auto list = bankingAccount.returnSelected(RequestedTransactions::all);
    numberOfTransactions = list.size();
    EXPECT_EQ(numberOfTransactions,25);

    EXPECT_TRUE(list[24]->getAmount() == -2000);
    EXPECT_TRUE(list[24]->getDescription() == "wire transfer");
    EXPECT_FALSE(list[24]->isProcessed());

    //wire transfer negated, controls after adding commissions
    int notAccepted = 7997;
    accepted = bankingAccount.createWireTransfer(make_tuple("IT31M02067215321000000003333",
        "Jack Jones","counseling service",-notAccepted));
    EXPECT_FALSE(accepted);
    EXPECT_EQ(bankingAccount.getDeposit(),7998);

    int maximumAccepted = 7996;
    accepted = bankingAccount.createWireTransfer(make_tuple("IT31M02067215321000000003333",
        "Jack Jones","counseling service",-maximumAccepted));
    EXPECT_TRUE(accepted);
    EXPECT_EQ(bankingAccount.getDeposit(),0);
}