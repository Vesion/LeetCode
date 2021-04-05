#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return get(s) == get(t);
    }
    string get(const string& s) {
        string r;
        for (char c : s) {
            if (c != '#') r += c;
            else if (!r.empty()) r.pop_back();
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
