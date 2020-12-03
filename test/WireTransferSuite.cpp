//
// Created by rebecca on 12/3/20.
//

#include "gtest/gtest.h"

#include "../project_files/banking_accounts_classes/WireTransfer.h"

TEST(WireTransferSuite, constructorAndSettersTest){
    WireTransfer wireTransfer(200);
    wireTransfer.setRecipient("Carlo Panerai","IT31M02067215321000000009234");
    wireTransfer.setSender("Alessia Cai","IT31M02067215321000000003214");
    wireTransfer.setReasonOfPayment("financial services");

    ASSERT_EQ(wireTransfer.getAmount(),200);
    ASSERT_EQ(wireTransfer.getDescription(),"wire transfer");
    ASSERT_EQ(wireTransfer.getCategory(),"general");
    ASSERT_EQ(wireTransfer.getReasonOfPayment(),"financial services");

    ASSERT_EQ(wireTransfer.getSender().first, "Alessia Cai");
    ASSERT_EQ(wireTransfer.getSender().second, "IT31M02067215321000000003214");

    ASSERT_EQ(wireTransfer.getRecipient().first, "Carlo Panerai");
    ASSERT_FALSE(wireTransfer.getRecipient().second == "IT21M02067215321000000009234");
}