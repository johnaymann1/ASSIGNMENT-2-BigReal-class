
#include "BigRealClass.h"
#include "BigDecimalIntClass.h"
#include "BigDecimalIntClass.cpp"

// #include "BigDecimalIntClass.h"

BigReal::BigReal(string realNumber){
    string before,after;
    int z;
    for(int i = 0; i < realNumber.size(); i++){
        if(realNumber[i] == '.') i = z;
    }
    for(int i = 0 ; i < z; i++){
        before += realNumber[i];
    }
    for(int i = z+1; i < realNumber.size(); i++){
        after += realNumber[i];
    }
    bPoint.setNumber(before);
    aPoint.setNumber(after);

}

BigReal::BigReal (const BigReal& other){
    bPoint = other.bPoint;
    aPoint = other.aPoint;
}

BigReal::BigReal (BigReal&& other){
    bPoint = move(other.bPoint);
    aPoint = move(other.aPoint);
}

BigReal& BigReal::operator= (BigReal& other){
    bPoint = other.bPoint;
    aPoint = other.aPoint;
}

BigReal& BigReal::operator= (BigReal&& other){
    bPoint = move(other.bPoint);
    aPoint = move(other.aPoint);
    return *this;
}

