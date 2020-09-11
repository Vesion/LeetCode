#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/string-transforms-into-another-string/discuss/355725/Graph-theory-analysis-of-this-problem
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        unordered_map<char,char> m;
        for (int i = 0; i < str1.size(); ++i) {
            if (m.count(str1[i]) && m[str1[i]] != str2[i]) return false;
            m[str1[i]] = str2[i];
        }
        unordered_set<char> s(str2.begin(), str2.end());
        return s.size() < 26;
    }
};


int main() {
    return 0;
}
