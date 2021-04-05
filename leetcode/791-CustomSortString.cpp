#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string customSortString(string order, string str) {
        int m[26] = {};
        for (char c : str) ++m[c-'a'];
        string res;
        for (char c : order) {
            res += string(m[c-'a'], c);
            m[c-'a'] = 0;
        }
        for (int i = 0; i < 26; ++i) res += string(m[i], i+'a');
        return res;
    }
};

int main() {
}
