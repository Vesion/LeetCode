#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        int i = 0;
        auto r = parse(formula, i);
        string res;
        for (const auto& p : r) {
            res += p.first;
            if (p.second > 1) res += to_string(p.second);
        }
        return res;
    }

    map<string, int> parse(const string& f, int& i) {
        map<string, int> res;
        for (; i < f.size(); ) {
            if (f[i] >= 'A' && f[i] <= 'Z') {
                string name(1, f[i++]);
                int c = 0;
                while (i < f.size() && islower(f[i])) name += f[i++];
                while (i < f.size() && isdigit(f[i])) c = c*10 + f[i++]-'0';
                if (c == 0) c = 1;
                res[name] += c;
            } else if (f[i] == '(') {
                auto t = parse(f, ++i);
                int c = 0;
                while (i < f.size() && isdigit(f[i])) c = c*10 + f[i++]-'0';
                if (c == 0) c = 1;
                for (const auto& p : t) res[p.first] += p.second * c;
            } else if (f[i] == ')') {
                ++i;
                break;
            }
        }
        return res;
    }

    bool isupper(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool islower(char c) {
        return c >= 'a' && c <= 'z';
    }
    bool isdigit(char c) {
        return c >= '0' && c <= '9';
    }
};


int main() {
}
