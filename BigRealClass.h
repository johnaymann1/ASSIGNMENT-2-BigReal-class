// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 2
// Program Name: BigDecimalInt
// Last Modification Date: 13/10/2022
// John Ayman Naim   20210107  S15
// Author2 and ID and Group: Aya Ali Hassan  ID: 20210083 (d, e)
// Author3 and ID and Group: Mohamed Ashraf Fahim  ID: 20210329 (f, i, j , k)
/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited decimal integer values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */
 
#ifndef BIGREAL_BIGREALCLASS_H
#define BIGREAL_BIGREALCLASS_H
#include <iostream>
#include <string>
#include "BigDecimalIntClass.h"

using namespace std;

class BigReal: public BigDecimalInt{
    private:
        BigDecimalInt bPoint;
        BigDecimalInt aPoint;
        char sign;
        int size;
    public:
        BigReal (double realNumber = 0.0); // Default constructor
        BigReal (string realNumber);
        BigReal (BigDecimalInt bigInteger);
        BigReal (const BigReal& other); // Copy constructor
        BigReal (BigReal&& other); // Move constructor
        BigReal& operator= (BigReal& other); // Assignment operator
        BigReal& operator= (BigReal&& other); // Move assignment
        bool operator==(BigReal other);
        bool operator>(BigReal other);
        char getsign();
        int getsize();

};

#endif
