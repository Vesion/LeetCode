#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    unordered_map<char, string> m1;
    unordered_map<string, char> m2;
    int m, n;

    bool wordPatternMatch(string pattern, string str) {
        m1.clear(), m2.clear();
        m = pattern.size(), n = str.size();
        return dfs(pattern, 0, str, 0);
    } 

    bool dfs(string& pattern, int pcur, string& str, int scur) {
        if (m-pcur > n-scur) return false; // prune
        if (pcur == m && scur == n) return true;
        if (pcur == m || scur == n) return false;

        char c = pattern[pcur];
        if (m1.count(c)) {
            string s = m1[c];
            if (str.substr(scur, s.size()) != s) return false;
            else return dfs(pattern, pcur+1, str, scur+s.size());
        } else {
            for (int i = scur; i < n; ++i) {
                string s = str.substr(scur, i-scur+1);
                if (m2.count(s)) continue;
                m1[c] = s;
                m2[s] = c;
                if (dfs(pattern, pcur+1, str, scur+s.size())) return true;
                m1.erase(c);
                m2.erase(s);
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.wordPatternMatch("abab", "redblueredblue") << endl;
    cout << s.wordPatternMatch("aaaa", "asdasdasdasd") << endl;
    cout << s.wordPatternMatch("aabb", "xyzabcxzyabc") << endl;
    cout << s.wordPatternMatch("aabb", "cdcdcdcd") << endl;
    return 0;
}
