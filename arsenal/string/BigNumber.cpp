#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string add(string num1, string num2) {
    string res;
    for (int i = num1.size()-1, j = num2.size()-1, carry = 0; i >= 0 || j >= 0 || carry; carry /= 10) {
        if (i >= 0) carry += num1[i--]-'0';
        if (j >= 0) carry += num2[j--]-'0';
        res += to_string(carry%10);
    }
    reverse(res.begin(), res.end());
    return res;
}

bool larger(string num1, string num2) {
    if (num1.size() != num2.size()) return num1.size() > num2.size();
    for (int i = 0; i < (int)num1.size(); ++i)
        if (num1[i] != num2[i]) return num1[i] > num2[i];
    return true;
}

string sub(string num1, string num2) {
    if (!larger(num1, num2)) return "-" + sub(num2, num1);
    string res;
    for (int i = num1.size()-1, j = num2.size()-1, carry = 0; i >= 0 || j >= 0; ) {
        int a = num1[i--]-'0'-carry;
        int b = j >= 0 ? num2[j--]-'0' : 0;
        if (a < b) { a += 10; carry = 1; } 
        else carry = 0;
        res += to_string(a-b);
    }
    reverse(res.begin(), res.end());
    auto it = res.find_first_not_of('0');
    return it == string::npos ? "0" : res.substr(it);
}

string mul(string num1, string num2) {
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
    //cout << add("99", "123") << endl;
    cout << sub("987654321", "123456789") << endl;
    //cout << mul("99", "123") << endl;
}
