#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

string mul(const string& a, const string& b) {
    int la = a.size(), lb = b.size();
    string c(la+lb, '0');
    for (int i = la-1; i >= 0; --i) {
        int carry = 0;
        for (int j = lb-1; j >= 0; --j) {
            carry += c[i+j+1]-'0' + (a[i]-'0')*(b[j]-'0');
            c[i+j+1] = carry%10 +'0';
            carry /= 10;
        }
        c[i] += carry;
    }
    auto it = c.find_first_not_of('0');
    return it == string::npos ? "0" : c.substr(it);
}

int main() {
    int N; cin >> N;
    string res = "1";
    while (N) res = mul(res, to_string(N--));
    cout << res << endl;
    return 0;
}
