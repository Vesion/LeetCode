#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> m(128, 0);
        for (char c : s) m[c]++;
        for (char c : t) if (m[c]-- == 0) return false;
        return true;
    }
};


int main() {
    return 0;
}
