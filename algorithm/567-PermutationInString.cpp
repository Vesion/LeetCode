#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m(128, 0);
        for (char& c : s1) m[c]++;
        int i = 0, j = 0, c = s1.size();
        while (j < (int)s2.size()) {
            if (m[s2[j++]]-- > 0) --c;
            if (c == 0) return true;
            if (j-i == (int)s1.size() && m[s2[i++]]++ >= 0) ++c;
        }
        return false;
    }
};


int main() {
    return 0;
}
