#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for (char &c : magazine) cnt[c-'a']++;
        for (char &c : ransomNote) {
            if (--cnt[c-'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}
