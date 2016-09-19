#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int m[26] = {0};    
        for (char &c : s) m[c-'a']++;
        for (char &c : t) {
            if (--m[c-'a'] < 0) return c;
        }
        return 0;
    }
};

int main() {
    Solution s;
    return 0;
}
