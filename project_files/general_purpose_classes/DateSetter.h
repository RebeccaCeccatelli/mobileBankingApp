//
// Created by rebecca on 10/21/20.
//

#ifndef MOBILE_BANKING_APP_DATESETTER_H
#define MOBILE_BANKING_APP_DATESETTER_H

#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;
using namespace boost::archive;

class DateSetter {
public:
    void setDate(string settedDate = "", char mode = 0);
    const string& getDate() const;

private:
    friend class boost::serialization::access;
    BOOST_SERIALIZATION_SPLIT_MEMBER();

    template <typename Archive>
    void save (Archive &ar, const unsigned int version) const;

    template <typename Archive>
    void load (Archive &ar, const unsigned int version);

    string convertDateToString() const;
    tm convertDateToTm() const;

    //attribute
    pair<tm,string> date;
};

#endif //MOBILE_BANKING_APP_DATESETTER_H
