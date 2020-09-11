#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return gets(S) == gets(T);
    }

    string gets(const string& s) {
        string res;
        for (char c : s) {
            if (c == '#') {
                // NOTE: pop_back an empty string is undefined
                // https://en.cppreference.com/w/cpp/string/basic_string/pop_back
                if (!res.empty()) res.pop_back();
            }
            else res.push_back(c);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
