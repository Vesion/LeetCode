#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if (n < 3) return false;
        for (int l1 = 1; l1 <= n/2; ++l1) {
            for (int l2 = 1; l2 <= n/2; ++l2) {
                if (valid(num.substr(0, l1), num.substr(l1, l2), num.substr(l1+l2))) return true;
            }
        }
        return false;
    }

    bool valid(string n1, string n2, string n3) {
        if ((n1.size() > 1 && n1[0] == '0') || (n2.size() > 1 && n2[0] == '0')) return false;
        string sum = add(n1, n2);
        if (sum == n3) return true;
        if (n3.size() < sum.size() || n3.find(sum) != 0) return false;
        return valid(n2, sum, n3.substr(sum.size()));
    }

    string add(string& n1, string& n2) {
        string res;
        for (int i = n1.size()-1, j = n2.size()-1, carry = 0; i >= 0 || j >= 0 || carry; carry /= 10) {
            if (i >= 0) carry += n1[i--]-'0';
            if (j >= 0) carry += n2[j--]-'0';
            res = to_string(carry%10) + res;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.isAdditiveNumber("199100199") << endl;
    cout << s.isAdditiveNumber("111122335588143") << endl;
    cout << s.isAdditiveNumber("1023") << endl;
    cout << s.isAdditiveNumber("123") << endl;
    cout << s.isAdditiveNumber("12012122436") << endl;

    return 0;
}

