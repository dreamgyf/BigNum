#include "biginteger.h"

using namespace std;

int BigInteger::to_int(char a) {
    return (int)(a - '0');
}

BigInteger::BigInteger()
{
    this->num = "0";
    negative = false;
}

BigInteger::BigInteger(unsigned num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigInteger::BigInteger(int num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigInteger::BigInteger(unsigned long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigInteger::BigInteger(long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigInteger::BigInteger(unsigned long long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigInteger::BigInteger(long long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigInteger::BigInteger(string num)
{
    if(num[0] == '-')
    {
        negative = true;
        num.erase(0,1);
    }
    else negative = false;
    while(num[0] == '0' && num.length() > 1)
    {
        num.erase(0,1);
    }
    if(num.empty())
    {
        throw "Error input!";
    }
    for(int i = 0;i < num.length();++i)
    {
        if(!(num[i] >= '0' && num[i] <= '9'))
        {
            throw "Error input!";
        }
    }
    if(negative == true && num != "0")
    {
        num.insert(num.begin(),'-');
    }
    this->num = num;
}

string BigInteger::to_string() const
{
    return this->num;
}

bool BigInteger::is_negative() const
{
    return negative ? true : false;
}

bool BigInteger::operator == (const BigInteger &another) const
{
    if(this->to_string() == another.to_string())
    {
        return true;
    }
    else
        return false;
}

bool BigInteger::operator != (const BigInteger &another) const
{
    if(this->to_string() == another.to_string())
    {
        return false;
    }
    else
        return true;
}

bool BigInteger::operator < (const BigInteger &another) const
{
    string a = this->to_string();
    string b = another.to_string();
    bool a_negative = this->is_negative();
    bool b_negative = another.is_negative();
    if(*this == another)
        return false;
    if(!a_negative && b_negative)
        return false;
    if(a_negative && !b_negative)
        return true;
    if(a_negative)
    {
        a.erase(0,1);
    }
    if(b_negative)
    {
        b.erase(0,1);
    }
    if(!a_negative && !b_negative)
    {
        if(a.length() < b.length())
        {
            return true;
        }
        else if(a.length() > b.length())
        {
            return false;
        }
        else
        {
            for(int i = 0;i < a.length();++i)
            {
                if(a[i] > b[i])
                {
                    return false;
                }
                else if(a[i] < b[i])
                {
                    return true;
                }
            }
        }
    }
    else if(a_negative && b_negative)
    {
        if(a.length() < b.length())
        {
            return false;
        }
        else if(a.length() > b.length())
        {
            return true;
        }
        else
        {
            for(int i = 0;i < a.length();++i)
            {
                if(a[i] > b[i])
                {
                    return true;
                }
                else if(a[i] < b[i])
                {
                    return false;
                }
            }
        }
    }
}

bool BigInteger::operator <= (const BigInteger &another) const
{
    if(*this == another || *this < another)
        return true;
    else
        return false;
}

bool BigInteger::operator > (const BigInteger &another) const
{
    string a = this->to_string();
    string b = another.to_string();
    bool a_negative = this->is_negative();
    bool b_negative = another.is_negative();
    if(*this == another)
        return false;
    if(!a_negative && b_negative)
        return true;
    if(a_negative && !b_negative)
        return false;
    if(a_negative)
    {
        a.erase(0,1);
    }
    if(b_negative)
    {
        b.erase(0,1);
    }
    if(!a_negative && !b_negative)
    {
        if(a.length() < b.length())
        {
            return false;
        }
        else if(a.length() > b.length())
        {
            return true;
        }
        else
        {
            for(int i = 0;i < a.length();++i)
            {
                if(a[i] > b[i])
                {
                    return true;
                }
                else if(a[i] < b[i])
                {
                    return false;
                }
            }
        }
    }
    else if(a_negative && b_negative)
    {
        if(a.length() < b.length())
        {
            return true;
        }
        else if(a.length() > b.length())
        {
            return false;
        }
        else
        {
            for(int i = 0;i < a.length();++i)
            {
                if(a[i] > b[i])
                {
                    return false;
                }
                else if(a[i] < b[i])
                {
                    return true;
                }
            }
        }
    }
}

bool BigInteger::operator >= (const BigInteger &another) const
{
    if(*this == another || *this > another)
        return true;
    else
        return false;
}

BigInteger BigInteger::operator + (const BigInteger &another) const
{
    string a = this->to_string();
    string b = another.to_string();
    string res;
    int residue = 0;
    bool a_negative = this->is_negative();
    bool b_negative = another.is_negative();
    if(a_negative && !b_negative)
    {
        a.erase(0,1);
        return BigInteger(b) - BigInteger(a);
    }
    else if(!a_negative && b_negative)
    {
        b.erase(0,1);
        return BigInteger(a) - BigInteger(b);
    }
    else if(a_negative && b_negative)
    {
        a.erase(0,1);
        b.erase(0,1);
    }
    while(a.length() > b.length())
    {
        b.insert(b.begin(),'0');
    }
    while(a.length() < b.length())
    {
        a.insert(a.begin(),'0');
    }
    for(int i = a.length() - 1;i >= 0;--i)
    {
        if(to_int(a[i]) + to_int(b[i]) + residue < 10)
        {
            res.insert(res.begin(),to_int(a[i]) + to_int(b[i]) + residue + '0');
            residue = 0;
        }
        else
        {
            res.insert(res.begin(),to_int(a[i]) + to_int(b[i]) + residue - 10 + '0');
            residue = 1;
        }
    }
    if(residue == 1)
        res.insert(res.begin(),'1');
    if(a_negative && b_negative)
        res.insert(res.begin(),'-');
    return BigInteger(res);
}

BigInteger BigInteger::operator - (const BigInteger &another) const
{
    string a = this->to_string();
    string b = another.to_string();
    string res;
    int residue = 0;
    string max,min;
    bool a_negative = this->is_negative();
    bool b_negative = another.is_negative();
    if(a_negative && !b_negative)
    {
        a.erase(0,1);
        return (BigInteger(a) + BigInteger(b)) * BigInteger(-1);
    }
    else if(!a_negative && b_negative)
    {
        b.erase(0,1);
        return BigInteger(a) + BigInteger(b);
    }
    else if(a_negative && b_negative)
    {
        a.erase(0,1);
        b.erase(0,1);
        return BigInteger(b) - BigInteger(a);
    }
    if(BigInteger(a) >= BigInteger(b))
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    while(min.length() < max.length())
    {
        min.insert(min.begin(),'0');
    }
    for(int i = max.length() - 1;i >= 0;--i)
    {
        if(max[i] < min[i] + residue)
        {
            res.insert(res.begin(),to_int(max[i]) + 10 - to_int(min[i]) - residue + '0');
            residue = 1;
        }
        else
        {
            res.insert(res.begin(),to_int(max[i]) - to_int(min[i]) - residue + '0');
            residue = 0;
        }
    }
    if(max == b)
        res.insert(res.begin(),'-');
    return BigInteger(res);
}

BigInteger BigInteger::operator * (const BigInteger &another) const
{
    string a = this->to_string();
    string b = another.to_string();
    BigInteger res;
    int residue = 0;
    string temp;
    vector<string> sum;
    bool a_negative = this->is_negative();
    bool b_negative = another.is_negative();
    if(a_negative && !b_negative)
    {
        a.erase(0,1);
    }
    else if(!a_negative && b_negative)
    {
        b.erase(0,1);
    }
    else if(a_negative && b_negative)
    {
        a.erase(0,1);
        b.erase(0,1);
    }
    for(int i = b.length() - 1;i >= 0;--i)
    {
        temp = "";
        for(int j = a.length() - 1;j >=0;--j)
        {
            temp.insert(temp.begin(),(to_int(a[j]) * to_int(b[i]) + residue) % 10 + '0');
            residue = (to_int(a[j]) * to_int(b[i]) + residue) / 10;
        }
        if(residue != 0)
        {
            temp.insert(temp.begin(),residue + '0');
            residue = 0;
        }
        sum.push_back(temp);
    }
    for(int i = 0;i < sum.size();++i)
    {
        for(int n = i;n > 0;--n)
        {
            sum[i] += '0';
        }
        res = res + BigInteger(sum[i]);
    }
    if((!a_negative && b_negative) || (a_negative && !b_negative))
        return BigInteger(0) - res;
    return res;
}

BigInteger BigInteger::operator / (const BigInteger &another) const
{
    string a = this->to_string();
    string b = another.to_string();
    bool a_negative = this->is_negative();
    bool b_negative = another.is_negative();
    if(b == "0")
        throw "The divisor can not be zero!";
    if(a_negative && !b_negative)
    {
        a.erase(0,1);
    }
    else if(!a_negative && b_negative)
    {
        b.erase(0,1);
    }
    else if(a_negative && b_negative)
    {
        a.erase(0,1);
        b.erase(0,1);
    }
    BigInteger residue(a);
    BigInteger add,temp,count,res;
    long long digit = a.length() - b.length();
    while(residue >= BigInteger(b))
    {
        add = BigInteger(1);
        count = BigInteger(0);
        for(long long n = 0;n < digit;++n)
        {
            add = add * BigInteger(10);
        }
        digit--;
        temp = BigInteger(b) * add;
        while(residue >= temp)
        {
            residue = residue - temp;
            count = count + BigInteger(1);
        }
        res = res + (count * add);
    }
    if((!a_negative && b_negative) || (a_negative && !b_negative))
        return BigInteger(0) - res;
    return res;
}

BigInteger BigInteger::operator % (const BigInteger &another) const
{
    return *this - (*this / another * another);
}

void BigInteger::operator += (const BigInteger &another)
{
    *this = *this + another;
}

void BigInteger::operator -= (const BigInteger &another)
{
    *this = *this - another;
}

void BigInteger::operator *= (const BigInteger &another)
{
    *this = *this * another;
}

void BigInteger::operator /= (const BigInteger &another)
{
    *this = *this / another;
}

void BigInteger::operator %= (const BigInteger &another)
{
    *this = *this % another;
}
