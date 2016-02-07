#include <iostream>
#include <string>
#include <map>
using namespace std;

// cannot solve by myself, refer to others

// greedy, O(n)
// use two maps for 'has' and 'need', two pointers for 'start' and 'end'
string minWindow(string s, string t) {
    if (s.empty() || s.size() < t.size())
        return "";

    map<char, int> has, need;
    for (auto c : t) {
        need[c]++;
        has[c] = 0;
    }
    int count = 0; // count the characters we neeed
    int windowStart = 0, windowEnd = 0; // index window
    int minStart = 0, minLen = INT_MAX; // for return

    for (; windowEnd < s.size(); ++windowEnd) {
        if (need.find(s[windowEnd]) == need.end()) // do not care characters we do not need
            continue;
        if (has[s[windowEnd]] < need[s[windowEnd]]) // count we need
            ++count;
        ++has[s[windowEnd]]; // count we has

        if (count == t.size()) { // find a window
            while (windowStart < windowEnd) { // let windowStart go forward to get away redundant 'has'
                if (need.find(s[windowStart]) == need.end())
                    ++windowStart;
                else if (has[s[windowStart]] > need[s[windowStart]]) {
                    --has[s[windowStart]];
                    ++windowStart;
                }
                else
                    break;
            }
            int len = windowEnd - windowStart + 1; // greedy, get minimum window
            if (len < minLen) {
                minLen = len;
                minStart = windowStart;
            }
        }

    }

    if (minLen == INT_MAX) return "";
    return s.substr(minStart, minLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
