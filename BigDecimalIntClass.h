// FCAI – Object-Oriented Programming 1 – 2022 - Assignment 1
// Program Name: BigDecimalInt
// Last Modification Date: 13/10/2022

/*
description: In this problem we developed a new C++ type (class).
that can hold unlimited decimal integer values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */

#ifndef BIGDECIMALINTCLASS_H_INCLUDED
#define BIGDECIMALINTCLASS_H_INCLUDED

#include <iostream>
#include <deque>
#include <regex>
#include <bits/stdc++.h>

using namespace std;

class BigDecimalInt{
private:
    string number;
    bool checkValidInput(string input);

public:
    char signNumber;
    bool operator < (const BigDecimalInt& anotherDec);
    bool operator > (const BigDecimalInt& anotherDec);
    bool operator == (const BigDecimalInt anotherDec);
    BigDecimalInt& operator = (BigDecimalInt anotherDec);
    BigDecimalInt operator + (BigDecimalInt number2);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    friend ostream &operator << (ostream &out, BigDecimalInt num);
    int size();
    int sign();
    void setNumber(string num);
    void setSign(char sign);
    string getNumber(){
        return number;
    }

    BigDecimalInt(){}
    BigDecimalInt(string num)
    {
        setNumber(num);
    }

};

#endif  //BIGDECIMALINTCLASS_H_INCLUDED
