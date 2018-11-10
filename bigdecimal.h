#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H

#include <string>
#include <vector>

using namespace std;

class BigDecimal
{
public:
    enum MODE {ROUND_UP,ROUND_DOWN};
    BigDecimal();
    BigDecimal(unsigned num);
    BigDecimal(int num);
    BigDecimal(unsigned long num);
    BigDecimal(long num);
    BigDecimal(unsigned long long num);
    BigDecimal(long long num);
    BigDecimal(float num);
    BigDecimal(double num);
    BigDecimal(long double num);
    BigDecimal(string num);
    string to_string() const;
    bool is_negative() const;
    void set_scale(unsigned num);
    void set_mode(enum MODE mode);
    static int to_int(char a);
    bool operator == (const BigDecimal &another) const;
    bool operator != (const BigDecimal &another) const;
    bool operator < (const BigDecimal &another) const;
    bool operator <= (const BigDecimal &another) const;
    bool operator > (const BigDecimal &another) const;
    bool operator >= (const BigDecimal &another) const;
    BigDecimal operator + (const BigDecimal &another) const;
    BigDecimal operator - (const BigDecimal &another) const;
    BigDecimal operator * (const BigDecimal &another) const;
    BigDecimal operator / (const BigDecimal &another) const;
    void operator += (const BigDecimal &another);
    void operator -= (const BigDecimal &another);
    void operator *= (const BigDecimal &another);
    void operator /= (const BigDecimal &another);

private:
    string num;
    bool negative;
    enum MODE mode = ROUND_UP;
    unsigned scale = 10;
};

#endif // BIGDECIMAL_H
