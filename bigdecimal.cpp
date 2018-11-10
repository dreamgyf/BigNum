#include "bigdecimal.h"

int BigDecimal::to_int(char a) {
    return (int)(a - '0');
}

BigDecimal::BigDecimal()
{
    this->num = "0";
    negative = false;
}

BigDecimal::BigDecimal(unsigned num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(int num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(unsigned long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(unsigned long long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(long long num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(float num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(double num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(long double num)
{
    this->num = std::to_string(num);
    if(this->num[0] == '-')
        negative = true;
    else
        negative = false;
}

BigDecimal::BigDecimal(string num)
{
    if(num[0] == '-')
    {
        negative = true;
        num.erase(0,1);
    }
    else
        negative = false;
    int dot1 = num.find('.');
    int dot2 = num.rfind('.');
    if(dot1 != dot2)
    {
        throw "Error input!";
    }
    while(num[0] == '0' && num.length() > 1)
    {
        num.erase(0,1);
    }
    if(num.empty())
    {
        throw "Error input!";
    }
    int dot = num.find('.');
    if(dot == 0)
    {
        num.insert(num.begin(),'0');
        dot++;
    }
    for(int i = 0;i < num.length();++i)
    {
        if(i == dot)
            continue;
        if(!(num[i] >= '0' && num[i] <= '9'))
        {
            throw "Error input!";
        }
    }
    while(dot != string::npos && num[num.length() - 1] == '0')
    {
        num.erase(num.length() - 1,1);
    }
    if(num[num.length() - 1] == '.')
    {
        num.erase(num.length() - 1,1);
    }
    if(negative == true && num != "0")
    {
        num.insert(num.begin(),'-');
    }
    this->num = num;
}

string BigDecimal::to_string() const
{
    return this->num;
}

bool BigDecimal::is_negative() const
{
    return negative ? true : false;
}

void BigDecimal::set_scale(unsigned num)
{
    this->scale = num;
}

void BigDecimal::set_mode(MODE mode)
{
    this->mode = mode;
}

bool BigDecimal::operator == (const BigDecimal &another) const
{
    if(this->to_string() == another.to_string())
    {
        return true;
    }
    else
        return false;
}

bool BigDecimal::operator != (const BigDecimal &another) const
{
    if(this->to_string() == another.to_string())
    {
        return false;
    }
    else
        return true;
}

bool BigDecimal::operator < (const BigDecimal &another) const
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
    int a_dot = a.find('.');
    int b_dot = b.find('.');
    string a_integer,b_integer,a_decimal,b_decimal;
    if(a_dot == string::npos)
    {
        a_integer = a;
        a_decimal = "0";
    }
    else
    {
        a_integer = a.substr(0,a_dot);
        a_decimal = a.substr(a_dot + 1);
    }
    if(b_dot == string::npos)
    {
        b_integer = b;
        b_decimal = "0";
    }
    else
    {
        b_integer = b.substr(0,b_dot);
        b_decimal = b.substr(b_dot + 1);
    }
    if(!a_negative && !b_negative)
    {
        if(a_integer == b_integer)
        {
            if(a_decimal.length() < b_decimal.length())
            {
                return true;
            }
            else if(a_decimal.length() > b_decimal.length())
            {
                return false;
            }
            else
            {
                for(int i = 0;i < a_decimal.length();++i)
                {
                    if(a_decimal[i] > b_decimal[i])
                    {
                        return false;
                    }
                    else if(a_decimal[i] < b_decimal[i])
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            if(a_integer.length() < b_integer.length())
            {
                return true;
            }
            else if(a_integer.length() > b_integer.length())
            {
                return false;
            }
            else
            {
                for(int i = 0;i < a_integer.length();++i)
                {
                    if(a_integer[i] > b_integer[i])
                    {
                        return false;
                    }
                    else if(a_integer[i] < b_integer[i])
                    {
                        return true;
                    }
                }
            }
        }
    }
    else if(a_negative && b_negative)
    {
        if(a_integer == b_integer)
        {
            if(a_decimal.length() < b_decimal.length())
            {
                return false;
            }
            else if(a_decimal.length() > b_decimal.length())
            {
                return true;
            }
            else
            {
                for(int i = 0;i < a_decimal.length();++i)
                {
                    if(a_decimal[i] > b_decimal[i])
                    {
                        return true;
                    }
                    else if(a_decimal[i] < b_decimal[i])
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            if(a_integer.length() < b_integer.length())
            {
                return false;
            }
            else if(a_integer.length() > b_integer.length())
            {
                return true;
            }
            else
            {
                for(int i = 0;i < a_integer.length();++i)
                {
                    if(a_integer[i] > b_integer[i])
                    {
                        return true;
                    }
                    else if(a_integer[i] < b_integer[i])
                    {
                        return false;
                    }
                }
            }
        }
    }
}

bool BigDecimal::operator <= (const BigDecimal &another) const
{
    if(*this == another || *this < another)
        return true;
    else
        return false;
}

bool BigDecimal::operator > (const BigDecimal &another) const
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
    int a_dot = a.find('.');
    int b_dot = b.find('.');
    string a_integer,b_integer,a_decimal,b_decimal;
    if(a_dot == string::npos)
    {
        a_integer = a;
        a_decimal = "0";
    }
    else
    {
        a_integer = a.substr(0,a_dot);
        a_decimal = a.substr(a_dot + 1);
    }
    if(b_dot == string::npos)
    {
        b_integer = b;
        b_decimal = "0";
    }
    else
    {
        b_integer = b.substr(0,b_dot);
        b_decimal = b.substr(b_dot + 1);
    }
    if(!a_negative && !b_negative)
    {
        if(a_integer == b_integer)
        {
            if(a_decimal.length() < b_decimal.length())
            {
                return false;
            }
            else if(a_decimal.length() > b_decimal.length())
            {
                return true;
            }
            else
            {
                for(int i = 0;i < a_decimal.length();++i)
                {
                    if(a_decimal[i] > b_decimal[i])
                    {
                        return true;
                    }
                    else if(a_decimal[i] < b_decimal[i])
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            if(a_integer.length() < b_integer.length())
            {
                return false;
            }
            else if(a_integer.length() > b_integer.length())
            {
                return true;
            }
            else
            {
                for(int i = 0;i < a_integer.length();++i)
                {
                    if(a_integer[i] > b_integer[i])
                    {
                        return true;
                    }
                    else if(a_integer[i] < b_integer[i])
                    {
                        return false;
                    }
                }
            }
        }
    }
    else if(a_negative && b_negative)
    {
        if(a_integer == b_integer)
        {
            if(a_decimal.length() < b_decimal.length())
            {
                return true;
            }
            else if(a_decimal.length() > b_decimal.length())
            {
                return false;
            }
            else
            {
                for(int i = 0;i < a_decimal.length();++i)
                {
                    if(a_decimal[i] > b_decimal[i])
                    {
                        return false;
                    }
                    else if(a_decimal[i] < b_decimal[i])
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            if(a_integer.length() < b_integer.length())
            {
                return true;
            }
            else if(a_integer.length() > b_integer.length())
            {
                return false;
            }
            else
            {
                for(int i = 0;i < a_integer.length();++i)
                {
                    if(a_integer[i] > b_integer[i])
                    {
                        return false;
                    }
                    else if(a_integer[i] < b_integer[i])
                    {
                        return true;
                    }
                }
            }
        }
    }
}

bool BigDecimal::operator >= (const BigDecimal &another) const
{
    if(*this == another || *this > another)
        return true;
    else
        return false;
}

BigDecimal BigDecimal::operator + (const BigDecimal &another) const
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
        return BigDecimal(b) - BigDecimal(a);
    }
    else if(!a_negative && b_negative)
    {
        b.erase(0,1);
        return BigDecimal(a) - BigDecimal(b);
    }
    else if(a_negative && b_negative)
    {
        a.erase(0,1);
        b.erase(0,1);
    }
    int a_dot = a.find('.');
    int b_dot = b.find('.');
    if(a_dot == string::npos)
    {
        a.insert(a.end(),'.');
        a_dot = a.length() - 1;
    }
    if(b_dot == string::npos)
    {
        b.insert(b.end(),'.');
        b_dot = b.length() - 1;
    }
    if(a_dot <= b_dot)
    {
        for(int i = 0;i < b_dot - a_dot;++i)
        {
            a.insert(a.begin(),'0');
        }
    }
    else
    {
        for(int i = 0;i < a_dot - b_dot;++i)
        {
            b.insert(b.begin(),'0');
        }
    }
    while(a.length() > b.length())
    {
        b.insert(b.end(),'0');
    }
    while(a.length() < b.length())
    {
        a.insert(a.end(),'0');
    }
    int dot = a.find('.');
    for(int i = a.length() - 1;i >= 0;--i)
    {
        if(i == dot)
            continue;
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
    res.insert(res.begin() + dot,'.');
    if(residue == 1)
        res.insert(res.begin(),'1');
    if(a_negative && b_negative)
        res.insert(res.begin(),'-');
    return BigDecimal(res);
}

BigDecimal BigDecimal::operator - (const BigDecimal &another) const
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
        return (BigDecimal(a) + BigDecimal(b)) * BigDecimal(-1);
    }
    else if(!a_negative && b_negative)
    {
        b.erase(0,1);
        return BigDecimal(a) + BigDecimal(b);
    }
    else if(a_negative && b_negative)
    {
        a.erase(0,1);
        b.erase(0,1);
        return BigDecimal(b) - BigDecimal(a);
    }
    if(BigDecimal(a) >= BigDecimal(b))
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    int max_dot = max.find('.');
    int min_dot = min.find('.');
    if(max_dot == string::npos)
    {
        max.insert(max.end(),'.');
        max_dot = max.length() - 1;
    }
    if(min_dot == string::npos)
    {
        min.insert(min.end(),'.');
        min_dot = min.length() - 1;
    }
    if(max_dot > min_dot)
    {
        for(int i = 0;i < max_dot - min_dot;++i)
            min.insert(min.begin(),'0');
    }
    while(max.length() > min.length())
    {
        min.insert(min.end(),'0');
    }
    while(max.length() < min.length())
    {
        max.insert(max.end(),'0');
    }
    int dot = max.find('.');
    for(int i = max.length() - 1;i >= 0;--i)
    {
        if(i == dot)
            continue;
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
    res.insert(res.begin() + dot,'.');
    if(max == b)
        res.insert(res.begin(),'-');
    return BigDecimal(res);
}

BigDecimal BigDecimal::operator * (const BigDecimal &another) const
{
    string a = this->to_string();
    string b = another.to_string();
    BigDecimal res;
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
    int a_dot = a.find('.');
    int b_dot = b.find('.');
    int points = 0;
    if(a_dot != string::npos)
    {
        a.erase(a_dot,1);
        points += a.length() - 1 - a_dot;
    }
    if(b_dot != string::npos)
    {
        b.erase(b_dot,1);
        points += b.length() - 1 - b_dot;
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
        res = res + BigDecimal(sum[i]);
    }
    string full_res = res.to_string();
    full_res.insert(full_res.begin() + (full_res.length() - points),'.');
    if((!a_negative && b_negative) || (a_negative && !b_negative))
    {
        full_res.insert(full_res.begin(),'-');
    }
    return BigDecimal(full_res);
}

BigDecimal BigDecimal::operator / (const BigDecimal &another) const
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
    int a_dot = a.find('.');
    int b_dot = b.find('.');
    if(a_dot == string::npos)
    {
        a.insert(a.end(),'.');
        a_dot = a.length() - 1;
    }
    if(b_dot == string::npos)
    {
        b.insert(b.end(),'.');
        b_dot = b.length() - 1;
    }
    if(a_dot <= b_dot)
    {
        for(int i = 0;i < b_dot - a_dot;++i)
        {
            a.insert(a.begin(),'0');
        }
    }
    else
    {
        for(int i = 0;i < a_dot - b_dot;++i)
        {
            b.insert(b.begin(),'0');
        }
    }
    while(a.length() > b.length())
    {
        b.insert(b.end(),'0');
    }
    while(a.length() < b.length())
    {
        a.insert(a.end(),'0');
    }
    int dot = a.find('.');
    a.erase(dot,1);
    b.erase(dot,1);
    while(a[0] == '0' && a.length() > 1)
    {
        a.erase(0,1);
    }
    while(b[0] == '0' && b.length() > 1)
    {
        b.erase(0,1);
    }
    BigDecimal residue(a);
    BigDecimal big_b(b);
    BigDecimal add,temp,count,integer_res;
    string decimal_res,res;
    long long digit = a.length() - b.length();
    while(residue >= big_b)
    {
        add = BigDecimal(1);
        count = BigDecimal(0);
        for(long long n = 0;n < digit;++n)
        {
            add = add * BigDecimal(10);
        }
        digit--;
        temp = big_b * add;
        while(residue >= temp)
        {
            residue = residue - temp;
            count = count + BigDecimal(1);
        }
        integer_res = integer_res + (count * add);
    }
    while(residue.to_string() != "0" && decimal_res.length() <= scale)
    {
        residue = residue * BigDecimal(10);
        count = BigDecimal(0);
        while(residue >= big_b)
        {
            residue = residue - big_b;
            count = count + BigDecimal(1);
        }
        decimal_res += count.to_string();
    }
    BigDecimal big_res;
    if(!decimal_res.empty())
    {
        bool carry_bit;
        if(mode == MODE::ROUND_UP)
        {
            if(decimal_res[decimal_res.length() - 1] >= '5')
                carry_bit = true;
            else
                carry_bit = false;
        }
        else
            carry_bit = false;
        decimal_res.erase(decimal_res.length() - 1,1);
        res = integer_res.to_string() + '.' + decimal_res;
        big_res = BigDecimal(res);
        if(carry_bit)
        {
            if(scale > 0)
            {
                string add_bit = "0.";
                for(int i = 1;i < decimal_res.length();++i)
                {
                    add_bit += '0';
                }
                add_bit += '1';
                big_res = big_res + BigDecimal(add_bit);
            }
            else
            {
                big_res = big_res + BigDecimal(1);
            }
        }
    }
    else
    {
        res = integer_res.to_string();
        big_res = BigDecimal(res);
    }
    if((!a_negative && b_negative) || (a_negative && !b_negative))
    {
        big_res = big_res * BigDecimal(-1);
    }
    return big_res;
}

void BigDecimal::operator += (const BigDecimal &another)
{
    *this = *this + another;
}

void BigDecimal::operator -= (const BigDecimal &another)
{
    *this = *this - another;
}

void BigDecimal::operator *= (const BigDecimal &another)
{
    *this = *this * another;
}

void BigDecimal::operator /= (const BigDecimal &another)
{
    *this = *this / another;
}
