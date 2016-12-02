#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<128> m;
        for (char c : s) m.flip(c);
        return m.count() < 2;
    }
};

int main() {
    Solution s;
    return 0;
}
