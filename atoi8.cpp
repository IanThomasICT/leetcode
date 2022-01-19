#include <iostream>
#include <string>

using namespace std;

int myAtoi(string s) {
    // Iterate through string
    long long result = 0;
    bool maxed = false, negative = false, integer = false;
    bool twochar = false; // tracks if a non-int was checked
    for (int i = 0; i < s.size(); i++){
        if (toupper(s[i]) >= 'A' && toupper(s[i]) <= 'Z' || s[i] == '.')
            break; 
        else if ((integer || twochar) && (s[i] < 48 || s[i] > 57))
            break;
        else if (s[i] == ' ') // Skip spaces
            continue;
        else if (s[i] == '-'){ // Make integer negative
            negative = true; 
            twochar = true;
        } else if (s[i] == '+') 
            twochar = true;
        else {
            integer = true;
            if (s[i] + 0 >= 47 && s[i]+0 <= 57){
                if (result *10 + s[i] - 48 >= 2147483648){ // Hard coded because I don't know how to do 2^31
                    result = 2147483648;
                    maxed = true;
                    break;
                } else {
                    result *= 10;               // increase base by 1
                    result += (s[i] - 48);         // convert char to int
                }
            }
        }
    }


    if (negative)
        return result * -1;
    else if (maxed == true)
        return --result;
    else
        return result;
}

int main() {
    string str = " b11228552307";
    cout << myAtoi(str) << endl;


}