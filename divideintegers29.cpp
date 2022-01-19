#include <iostream>
#include <cmath>

using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == 0)
        return 0;
    if (divisor == 0)
        return 2147483647;
    
    
    long long result = 0;
    bool negative = false, maxNeg = false;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
        negative = true;
    if (dividend == -2147483648){
        dividend = 2147483647;
        maxNeg = true;
    }
    divisor = abs(divisor); dividend = abs(dividend);
    while (dividend >= divisor && result < 2147483647){
        dividend -= divisor;
        result++;
        if (result == 2147483647 && !negative)
            return 2147483647;
    }

    if (maxNeg && divisor == 1){
        result *= -1;
        return --result;
    } else if (negative)
        return result *= -1;
    else 
        return result;
}

int main() {

    cout << divide(-2147483648,-1) << endl;


}