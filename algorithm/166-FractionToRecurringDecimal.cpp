#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long long a = labs(numerator), b = labs(denominator);

        string res = (numerator > 0) ^ (denominator > 0) ? "-" : "";
        res += to_string(a/b);
        a %= b;
        if (a == 0) return res;

        res += ".";
        unordered_map<int, int> m;
        while (a) {
            a *= 10;
            if (m.count(a)) { // find repeating
                res.insert(m[a], "(");
                res += ")";
                break;
            }
            res += to_string(a/b);
            m[a] = res.size()-1;
            a %= b;
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.fractionToDecimal(1000, 20) << endl;
    return 0;
}

