#include "BigReal.h"
#include "BigDecimalIntClass.h"
#include "BigDecimalIntClass.cpp"

//#include "BigDecimalIntClass.h"

BigReal::BigReal(string realNumber){
    string before,after;
    int z;
    while (realNumber.at(realNumber.length() - 1)=='0')
    {
        realNumber.pop_back();
    }
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
    return *this;
}

BigReal& BigReal::operator= (BigReal&& other){
    bPoint = move(other.bPoint);
    aPoint = move(other.aPoint);
    return *this;
}
char BigReal :: getsign(){
    return sign;
}
int BigReal:: getsize(){
    return size;
}
bool BigReal:: operator>(BigReal other)
{
    if (sign=='+'&&other.sign=='-')
        return true;
    else if (sign=='-'&&other.sign=='+')
        return false;
    if ((bPoint.size()>other.bPoint.size())&&(sign=='+')&&(other.sign=='+'))
        return true;
    if ((bPoint.size()> other.bPoint.size())&&(sign=='-')&&(other.sign=='-'))
        return false;
    if ((bPoint.size()==other.bPoint.size())&&(sign=='+')&&(other.sign=='+'))
    {
        for (int i=0;i<bPoint.size();i++)
        {
           if(bPoint.getNumber()[i] >other.bPoint.getNumber()[i])
              return true;
            else if (bPoint.getNumber()[i]<other.bPoint.getNumber()[i])
                return false;

        }
        for (int i=0;i<bPoint.size();i++)
        {
            if (bPoint.getNumber()[i]==other.bPoint.getNumber()[i])
                {
                    if (aPoint.size()>other.aPoint.size()){
                        for (int i=0;i<aPoint.size();i++){
                                other.aPoint.getNumber()+='0';
                        }
                        for (int i=0 ;i<aPoint.size();i++){
                            if(aPoint.getNumber()[i]>other.aPoint.getNumber()[i])
                                return true;
                            else
                                return false;
                        }
                    }
                    else if (aPoint.size()<other.aPoint.size()){
                        for (int i=0;i<other.aPoint.size();i++){
                            aPoint.getNumber()+='0';
                        }
                        for (int i=0 ;i<other.aPoint.size();i++){
                            if(aPoint.getNumber()[i]>other.aPoint.getNumber()[i])
                                return true;
                            else
                                return false;

                        }
                    }
                }
            }
        }
}


bool BigReal:: operator==(BigReal other)
{
    if (sign=='+'&&other.sign=='+')
    {
        if (bPoint.size()==other.bPoint.size())
        {
            if (aPoint.size()==other.aPoint.size())
            {
                for (int i=0;i<bPoint.size();i++)
                    {
                        if (bPoint.getNumber()[i]==other.bPoint.getNumber()[i])
                            return true;
                        else if (bPoint.getNumber()[i]!=other.bPoint.getNumber()[i])
                            return false;
                    }
                for (int i=0;i<aPoint.size();i++)
                {
                    if (aPoint.getNumber()[i]==other.aPoint.getNumber()[i])
                        return true;
                    else if (aPoint.getNumber()[i]!=other.aPoint.getNumber()[i])
                            return false;
                }
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
    if (sign=='-'&&other.sign=='-')
    {
        if (bPoint.size()==other.bPoint.size())
        {
            if (aPoint.size()==other.aPoint.size())
            {
                for (int i=0;i<bPoint.size();i++)
                    {
                        if (bPoint.getNumber()[i]==other.bPoint.getNumber()[i])
                            return true;
                        else if (bPoint.getNumber()[i]!=other.bPoint.getNumber()[i])
                            return false;
                    }
                for (int i=0;i<aPoint.size();i++)
                {
                    if (aPoint.getNumber()[i]==other.aPoint.getNumber()[i])
                        return true;
                    else if (aPoint.getNumber()[i]!=other.aPoint.getNumber()[i])
                            return false;
                }
            }

            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}
ostream &operator<<(ostream &out, BigReal number)
{
    string str = number.getNumber();
    char s = number.getsign();
    if (s == '-')
        out << '-';
    for (int i = 0; i < str.size(); i++)
        out << str[i];
    return out;
}



