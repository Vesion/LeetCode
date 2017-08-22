#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

string add(string& num1, string& num2) {
    string res;
    for (int i = num1.size()-1, j = num2.size()-1, carry = 0; i >= 0 || j >= 0 || carry; carry /= 10) {
        if (i >= 0) carry += num1[i--]-'0';
        if (j >= 0) carry += num2[j--]-'0';
        res += to_string(carry%10);
    }
    reverse(res.begin(), res.end());
    return res;
}

string mul(string& num1, string& num2) {
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

int main() {
    string s1, s2;
    int n;
    cin >> s1 >> s2 >> n;
    for (int i = 3; i <= n; ++i) {
        string t = s2;
        s2 = mul(s2, s2);
        s2 = add(s1, s2);
        s1 = t;
    }
    cout << s2 << endl;
    return 0;
}
