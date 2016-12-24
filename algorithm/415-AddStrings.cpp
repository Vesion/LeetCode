#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        for (int i = num1.size()-1, j = num2.size()-1, carry = 0; i >= 0 || j >= 0 || carry; carry /= 10) {
            if (i >= 0) carry += num1[i--]-'0';
            if (j >= 0) carry += num2[j--]-'0';
            result = to_string(carry%10) + result;
        }
        return result;
    }
};


int main() {
    Solution s;
    cout << s.addStrings("9999999999999", "1")<<endl;
    return 0;
}
