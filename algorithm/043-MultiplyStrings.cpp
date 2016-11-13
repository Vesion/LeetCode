#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num1.empty()) return "";
        int n1 = num1.size(), n2 = num2.size();
        string res(n1+n2, '0');
        for (int i = n1-1; i >= 0; --i) {
            int carry = 0;
            for (int j = n2-1; j >= 0; --j) {
                carry += (res[i+j+1] - '0') + (num1[i]-'0') * (num2[j]-'0');
                res[i+j+1] = carry % 10 + '0';
                carry /= 10;
            }
            res[i] += carry;
        }
        auto it = res.find_first_not_of('0');
        return it == string::npos ? "0" : res.substr(it);
    }
};

int main() {
    Solution s;
    cout << s.multiply("98", "9");
    return 0;
}

