#include <iostream>
#include "biginteger.h"
#include "bigdecimal.h"

using namespace std;

int main()
{
    try
    {
        BigInteger a("123");
        BigInteger b("1000");
        cout << (a + b).to_string() << '\n' << (a - b).to_string() << '\n' << (a * b).to_string() << '\n' << (a / b).to_string() << '\n' << (a % b).to_string() << "\n\n\n\n\n";
        BigDecimal c("243543534.234624565426");
        BigDecimal d("124124426.52456256456");
        cout << (c + d).to_string() << '\n' << (c - d).to_string() << '\n' << (c * d).to_string() << '\n' ;
        cout << (c / d).to_string() << '\n' ;
    }
    catch(const char *c)
    {
        cout << c << endl;
    }
    return 0;
}
