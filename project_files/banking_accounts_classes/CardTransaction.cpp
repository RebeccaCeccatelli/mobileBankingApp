//
// Created by rebecca on 10/19/20.
//

#include "CardTransaction.h"

template<typename Archive>
void CardTransaction::serialize(Archive &ar, const unsigned int version) {
    ar & boost::serialization::base_object<Transaction>(*this);
    ar & cardNumber;
    ar & detectedLocation;
    ar & categorization;
}

BOOST_CLASS_EXPORT_GUID(CardTransaction, "CardTransaction"); //controllare che polimorfismo funzioni TODO

