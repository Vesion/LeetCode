#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string multiply(string& a, string& b) {
    int m = a.size(), n = b.size();
    string res(m+n, '0');
    int carry = 0;
    for (int i = m-1; i >= 0; --i) {
        carry = 0;
        for (int j = n-1; j >= 0; --j) {
            carry += (res[i+j+1]-'0') + (a[i]-'0') * (b[j]-'0');
            res[i+j+1] = carry%10 + '0';
            carry /= 10;
        }
        res[i] += carry;
    }
    auto pos = res.find_first_not_of('0');
    return pos == string::npos ? "0" : res.substr(pos);
}


int main() {
    string a,b; 
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}
