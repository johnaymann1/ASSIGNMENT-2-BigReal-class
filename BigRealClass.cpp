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
    if(realNumber[0] == '+')
        sign = '+';
    else if (realNumber[0] == '-')
        sign = '-';
    else
        sign = '+';
    bPoint = BigDecimalInt(before);
    aPoint = BigDecimalInt(after);

}

BigReal::BigReal (const BigReal& other){
    sign = other.sign;
    bPoint = other.bPoint;
    aPoint = other.aPoint;
}

BigReal::BigReal (BigReal&& other){
    sign = move(other.sign);
    bPoint = move(other.bPoint);
    aPoint = move(other.aPoint);
}

BigReal& BigReal::operator= (BigReal& other){
    sign = other.sign;
    bPoint = other.bPoint;
    aPoint = other.aPoint;
    return *this;
}

BigReal& BigReal::operator= (BigReal&& other){
    sign = move(other.sign);
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
bool BigReal:: operator>(BigReal &other)
{
    if (this->aPoint.size()>other.aPoint.size())
    {
        string apoint2=other.aPoint.getNumber();
        int apoint3= this->aPoint.size()- other.aPoint.size();
        apoint2.insert(other.aPoint.size(),apoint3,'0');
        other.aPoint.setNumber(apoint2);
    }
    else if (this->aPoint.size()<other.aPoint.size())
    {
        string apoint2=this->aPoint.getNumber();
        int apoint3= other.aPoint.size()- this->aPoint.size();
        apoint2.insert(this->aPoint.size(),apoint3,'0');
        this->aPoint.setNumber(apoint2);

    }
    if(this->bPoint>other.bPoint)
        return true;
    else if (this->bPoint < other.bPoint)
        return false;
    else if (this->bPoint ==other.bPoint&& this->aPoint> other.aPoint)
        return true;
    else
        return false;


}
bool BigReal:: operator<(BigReal &other)
{
    if (this->aPoint.size()>other.aPoint.size())
    {
        string apoint2=other.aPoint.getNumber();
        int apoint3= this->aPoint.size()- other.aPoint.size();
        apoint2.insert(other.aPoint.size(),apoint3,'0');
        other.aPoint.setNumber(apoint2);
    }
    else if (this->aPoint.size()<other.aPoint.size())
    {
        string apoint2=this->aPoint.getNumber();
        int apoint3= other.aPoint.size()- this->aPoint.size();
        apoint2.insert(this->aPoint.size(),apoint3,'0');
        this->aPoint.setNumber(apoint2);

    }
    if(this->bPoint < other.bPoint)
        return true;
    else if (this->bPoint > other.bPoint)
        return false;
    else if (this->bPoint ==other.bPoint&& this->aPoint < other.aPoint)
        return true;
    else
        return false;


}


bool BigReal:: operator==(BigReal &other)
{
    if (this->aPoint.size()>other.aPoint.size())
    {
        string apoint2=other.aPoint.getNumber();
        int apoint3= this->aPoint.size()- other.aPoint.size();
        apoint2.insert(other.aPoint.size(),apoint3,'0');
        other.aPoint.setNumber(apoint2);
    }
    else if (this->aPoint.size()<other.aPoint.size())
    {
        string apoint2=this->aPoint.getNumber();
        int apoint3= other.aPoint.size()- this->aPoint.size();
        apoint2.insert(this->aPoint.size(),apoint3,'0');
        this->aPoint.setNumber(apoint2);

    }
    if (this->bPoint==other.bPoint && this->aPoint==other.aPoint)

        return true;
    else
        return false;
}
ostream &operator<<(ostream &out, BigReal &realNumber)
{
    out<<realNumber.bPoint<<"."<<realNumber.aPoint;
    return out;


}

istream &operator>>(istream &in, BigReal &realNumber)
{
    string str;
    in>>str;
    realNumber=BigReal(str);
    return in;
}



void equal_fractions(BigDecimalInt &frac1,BigDecimalInt &frac2) //Puts '0' to make the two fractions equal in Size
{
    int s_f1=frac1.Size();
    int s_f2=frac2.Size();
    string str="";
    while(s_f1 < s_f2) // if the size of the second fraction is greater
    {
        s_f2--;
        str+='0';
        if(s_f1==s_f2)
        {
            str=(frac1.sign()==0?'-':'+')+frac1.getNumber()+str;
            frac1=BigDecimalInt(str);
        }
    }
    while(s_f2<s_f1)
    {
        s_f1--;
        str+='0';
        if(s_f1==s_f2)
        {
            str=(frac2.sign()==0?'-':'+')+frac2.getNumber()+str;
            frac2=BigDecimalInt(str);
        }
    }
}

//===============================================================

BigDecimalInt rightSfract(BigDecimalInt frac1,BigDecimalInt frac2)
{
    BigDecimalInt frac3;
    if(frac1.sign()!=frac2.sign())
    {
        int i=0;
        string str="";

        while(frac1.getNumber()[i]==frac2.getNumber()[i] && i < frac1.Size()-1)
        {
            str+='0';
            i++;
        }

        str=(frac3.sign()==0?"-":"+")+str+frac3.getNumber();
        frac3=BigDecimalInt(str);
    }

    return frac3;
}

//===============================================================

void same_sign(BigDecimalInt &integthi,BigDecimalInt &fracthi,BigDecimalInt fracfirst)
{
    string str;

    if(fracthi.Size()>fracfirst.Size())
    {
        str=fracthi.getNumber();
        str=str.substr(1,str.size()-1);
        fracthi=BigDecimalInt(str);
        integthi=integthi+BigDecimalInt("1");
    }
}


//===============================================================

void diff_sign(BigDecimalInt &beforeP,BigDecimalInt &afterP)
{
    string strinteger(beforeP.Size(),'0');
    string strfrac(afterP.Size(),'0');
 
    if(afterP.getNumber()!=strfrac)
    {
        if(beforeP.getNumber()==strinteger)
        {
            strinteger = (afterP.sign()==1?"+":"-")+strinteger;
            beforeP = BigDecimalInt(strinteger);
        }
        else
        {
            bool istrue = 1;
            string diff_frac = "";
            char ch;

            beforeP = beforeP + BigDecimalInt(beforeP.sign()==0?"+1":"-1");

            for(int i = afterP.Size()-1;i >=0; i--)
            {
                if(afterP.getNumber()[i]!= '0' && istrue == 1)
                {
                    istrue = 0;
                    ch ='9'- afterP.getNumber()[i]+49;
                    diff_frac=ch;
                }
                else if(!istrue)
                {
                    ch='9'-afterP.getNumber()[i]+48;
                    diff_frac = ch + diff_frac;
                }
            }
            afterP = BigDecimalInt(diff_frac);
        }
    }
}

//===============================================================

BigReal BigReal::operator+(BigReal other)
{
    BigReal num3;
    num3.bPoint= bPoint + other.bPoint;

    equal_fractions(aPoint,other.aPoint);
    num3.aPoint = aPoint + other.aPoint;
    
    num3.aPoint = rightSfract(aPoint,other.aPoint);

    if(num3.bPoint.sign()==num3.aPoint.sign())
    {
        same_sign(num3.bPoint,num3.aPoint,aPoint);
    }
    else
    {
        diff_sign(num3.bPoint,num3.aPoint);
    }

    return num3;
}

//===============================================================

BigReal BigReal::operator- (BigReal other)
{
    BigReal num3;

    string str1integ=(other.bPoint.sign()==0?"+":"-")+other.bPoint.getNumber();
    string str2frac=(other.aPoint.sign()==0?"+":"-")+other.aPoint.getNumber();

    other.bPoint = BigDecimalInt(str1integ);
    other.aPoint = BigDecimalInt(str2frac);

    num3.bPoint = bPoint + other.bPoint;
    equal_fractions(aPoint , other.aPoint);
    num3.aPoint = aPoint + other.aPoint;
    num3.aPoint = rightSfract(aPoint,other.aPoint);


    if(num3.bPoint.sign()==num3.aPoint.sign())
    {
        same_sign(num3.bPoint,num3.aPoint,aPoint);
    }
    else
    {
        diff_sign(num3.bPoint,num3.aPoint);
    }

    return num3;

}

===============================================================
