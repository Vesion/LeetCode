#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// convert fraction to decimal, hash table
// be careful with:
//      1. overflow, so use long long
//      2. negative number, add sign
//      3. use hash table to store position to construct recurring decimal
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long long a = llabs(numerator), b = llabs(denominator);

        string res = ((numerator < 0) ^ (denominator < 0)) ? "-" : "";
        res += to_string(a / b);
        a %= b;
        if (a == 0) return res;

        unordered_map<int, int> m;
        res += '.';
        while (a) {
            a *= 10;
            if (m.count(a)) {
                res.insert(m[a], "(");
                res += ")";
                break;
            }
            m[a] = res.size();
            res += to_string(a / b);
            a %= b;
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.fractionToDecimal(-1, INT_MIN) << endl;
    return 0;
}
