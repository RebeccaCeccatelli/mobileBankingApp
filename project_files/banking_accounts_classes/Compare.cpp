//
// Created by rebecca on 11/26/20.
//

#include "Compare.h"

bool Compare::operator()(const string &left, const string &right) const {
    int leftYear = stoi(left.substr(6,2)), leftMonth = stoi(left.substr(0,2)), leftDay = stoi(left.substr(3,2));
    int leftHour = stoi(left.substr(9,2)), leftMin = stoi(left.substr(12,2)), leftSec = stoi(left.substr(15, 2));
    int rightYear = stoi(right.substr(6,2)), rightMonth = stoi(right.substr(0,2)), rightDay = stoi(right.substr(3,2));
    int rightHour = stoi(right.substr(9,2)), rightMin = stoi(right.substr(12,2)), rightSec = stoi(right.substr(15,2));

    if (leftYear < rightYear)
        return true;
    else if (leftYear > rightYear)
        return false;
    else if (leftYear == rightYear){
        if (leftMonth < rightMonth)
            return true;
        else if (leftMonth > rightMonth)
            return false;
        else if (leftMonth == rightMonth){
            if (leftDay < rightDay)
                return true;
            else if (leftDay > rightDay)
                return false;
            else if (leftDay == rightDay){
                if (leftHour < rightHour)
                    return true;
                else if (leftHour > rightHour)
                    return false;
                else if (leftHour == rightHour) {
                    if (leftMin < rightMin)
                        return true;
                    else if (leftMin > rightMin)
                        return false;
                    else if (leftMin == rightMin) {
                        if (leftSec < rightSec)
                            return true;
                        else if (leftSec >= rightSec)
                            return false;
                    }
                }
            }
        }
    }
}
