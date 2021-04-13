#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int DivideIntegers(int dividend, int divisor);

int main()
{
    cout << DivideIntegers(10, 5) << "\n";

    cout << DivideIntegers(9, 3) << "\n";

    return 0;
}

int DivideIntegers(int dividend, int divisor)
{
    int result = 0;
    int aDividend = abs(dividend);
    int aDivisor = abs(divisor);

    int sign;
    if (dividend < 0 || divisor < 0)
    {
        sign = -1;
    }
    else
    {
        sign = 1;
    }
    
    
    while (aDividend >= aDivisor)
    {
        aDividend - aDivisor;
        result++;
    }
    return (int)result * sign;
}