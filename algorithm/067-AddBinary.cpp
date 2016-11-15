#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        for (int i = a.size()-1, j = b.size()-1, carry = 0; i >= 0 || j >= 0 || carry; carry >>= 1) {
            if (i >= 0) carry += a[i--]-'0';
            if (j >= 0) carry += b[j--]-'0';
            res.push_back((carry&1) + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
