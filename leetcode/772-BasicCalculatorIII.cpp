#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    using ll = long long;
    int calculate(string s) {
        int i = 0;
        return parse(s, i);
    }

    int parse(const string& s, int& i) {
        vector<ll> st;
        char op = '+';
        for (; i < s.size(); ++i) {
            ll num = s[i] == '(' ? parse(s, ++i) : parse_num(s, i);

            if (op == '+') st.push_back(num);
            else if (op == '-') st.push_back(-num);
            else if (op == '*') st.back() *= num;
            else if (op == '/') st.back() /= num;
            op = s[i];  // op could be +,-,*,/,)

            if (s[i] == ')') { ++i; break; }  // think why ++i
        }
        ll res = 0;
        for (ll t : st) res += t;
        return res;
    }

    ll parse_num(const string& s, int& i) {
        ll num = 0;
        for (; i < s.size() && isdigit(s[i]); ++i) {
            num = num*10 + s[i]-'0';
        }
        return num;
    }

    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }
};

int main() {

}