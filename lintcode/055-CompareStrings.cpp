#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool compareStrings(string A, string B) {
        if (A.size() < B.size()) return false;
        int ac[26] = {0};
        for (auto &c : A) ac[c-'A']++;
        for (auto &c : B) {
            if (ac[c-'A'] == 0) return false;
            ac[c-'A']--;
        }
        return true;
    } 
};

int main() {
    Solution s;
    cout << s.compareStrings("ABCD", "AF") << endl;
    return 0;
}
