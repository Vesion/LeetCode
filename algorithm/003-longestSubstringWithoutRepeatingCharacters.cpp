#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int lastRepeat = -1;
    unordered_map<char, int> m;
    for (int i=0; i<s.size(); ++i) {
        if (m.find(s[i]) != m.end() && lastRepeat < m[s[i]]) {
            lastRepeat = m[s[i]];
        }
        if (i - lastRepeat > maxLength) {
            maxLength = i - lastRepeat;
        }
        m[s[i]] = i;
    }
    return maxLength;
}

int main() {
    string s1 = "abcabcabcabcd";
    cout<<lengthOfLongestSubstring(s1)<<endl;
    return 0;
}
