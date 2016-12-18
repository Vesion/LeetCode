#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if (word.empty() && abbr.empty()) return true;
        int m = word.size(), n = abbr.size();
        if (m < n) return false;
        int i = 0, j = 0;
        while (j < n) {
            if (isalpha(abbr[j])) {
                if (word[i++] != abbr[j++]) return false;
            } else {
                if (abbr[j] == '0') return false;
                int num = 0;
                while (j < n && isdigit(abbr[j])) num = num*10 + (abbr[j++]-'0');
                i += num;
            }
        }
        return i == m;
    }
};

int main() {
    Solution s;
    cout << s.validWordAbbreviation("abcdefghijklmn", "10klmn") << endl;;
    return 0;
}

