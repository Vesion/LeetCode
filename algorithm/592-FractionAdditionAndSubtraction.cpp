#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int i = 0;
        auto res = parse(expression, i);
        int sign = ((res.first>0)^(res.second>0)) ? -1 : 1;
        int g = gcd(abs(res.first), abs(res.second));
        return to_string(sign*abs(res.first)/g) + "/" + to_string(abs(res.second)/g);
    }

    pair<int,int> parse(string& s, int& i) {
        if (i == (int)s.size()) return {0,1};
        int n = 0, d = 0, sign = 1;
        if (s[i] == '-') { sign = -1; ++i; }
        else if (s[i] == '+') { sign = 1; ++i; }
        while (isdigit(s[i])) n = n*10+(s[i++]-'0');
        ++i;
        while (isdigit(s[i])) d = d*10+(s[i++]-'0');
        auto t = parse(s, i);
        return {sign*n*t.second+t.first*d, d*t.second};
    }

    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a%b);
    }
};


int main() {
    return 0;
}
