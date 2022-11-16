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

#include "BigRealclass.cpp"
#include "BigReal.h"


int main()
{
    BigReal n1("-1234.24");
    BigReal n2("1234.233");
    if (n1>n2)
        cout<<n1 <<" > "<<n2;
    else if ( n1<n2)
        cout << n1<<" < "<<n2;
    else if (n1==n2)
        cout<< n1<<" = "<<n2;

    return 0;

}




