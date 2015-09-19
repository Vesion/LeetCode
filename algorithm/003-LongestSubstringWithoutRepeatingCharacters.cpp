#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/*
 * Using a map store each char's index.
 * So, we can be easy to know the when duplication and the previous duplicated char's index.
 * Then we can take out the previous duplicated char, and keep tracking the maxiumn length. 
 */
int lengthOfLongestSubstring(string s) {
    int maxLength = 0;
    int lastRepeat = -1;
    unordered_map<char, int> m;
    for (int i=0; i<s.size(); ++i) {
        // Why while lastRepeat < m[s[i]]?
        // Beacause the new substring starts from the char which is the closest to i.
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
