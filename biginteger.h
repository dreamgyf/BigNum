#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <string>
#include <vector>

using namespace std;

class BigInteger
{
public:
    BigInteger();
    BigInteger(unsigned num);
    BigInteger(int num);
    BigInteger(unsigned long num);
    BigInteger(long num);
    BigInteger(unsigned long long num);
    BigInteger(long long num);
    BigInteger(string num);
    string to_string() const;
    bool is_negative() const;
    static int to_int(char a);
    bool operator == (const BigInteger &another) const;
    bool operator != (const BigInteger &another) const;
    bool operator < (const BigInteger &another) const;
    bool operator <= (const BigInteger &another) const;
    bool operator > (const BigInteger &another) const;
    bool operator >= (const BigInteger &another) const;
    BigInteger operator + (const BigInteger &another) const;
    BigInteger operator - (const BigInteger &another) const;
    BigInteger operator * (const BigInteger &another) const;
    BigInteger operator / (const BigInteger &another) const;
    BigInteger operator % (const BigInteger &another) const;
    void operator += (const BigInteger &another);
    void operator -= (const BigInteger &another);
    void operator *= (const BigInteger &another);
    void operator /= (const BigInteger &another);
    void operator %= (const BigInteger &another);

private:
    string num;
    bool negative;
};

#endif // BIGINTEGER_H
