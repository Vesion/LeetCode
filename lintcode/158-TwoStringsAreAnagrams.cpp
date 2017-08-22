#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool anagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> sc;
        for (auto &c : s) sc[c]++;
        for (auto &c : t) {
            if (!sc.count(c) || !sc[c]) return false;
            sc[c]--;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.anagram("ead", "ae");
    return 0;
}
