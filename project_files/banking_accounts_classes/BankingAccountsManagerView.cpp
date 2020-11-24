//
// Created by rebecca on 11/21/20.
//

#include "BankingAccountsManagerView.h"

template<typename Archive>
void BankingAccountsManagerView::serialize(Archive &ar, const unsigned int version) {
    ar & bankingAccounts;
}
