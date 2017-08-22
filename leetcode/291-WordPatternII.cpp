#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> p_dict;
        unordered_map<string, char> s_dict;
        return dfs(pattern, 0, str, 0, p_dict, s_dict);
    }
    
    bool dfs(string& p, int p_start, string& s, int s_start, unordered_map<char, string>& p_dict, unordered_map<string, char>& s_dict) {
        if (p.size()-p_start > s.size()-s_start) return false; // very aggressive prune
        if (s_start > (int)s.size()) return false;
        if (p_start == (int)p.size()) return s_start == (int)s.size();
        char c = p[p_start];
        if (p_dict.count(c)) {
            string w = p_dict[c];
            if (s.substr(s_start, w.size()) != w) return false;
            else return dfs(p, p_start+1, s, s_start+w.size(), p_dict, s_dict);
        } else {
            for (int i = s_start; i < (int)s.size(); ++i) {
                string w = s.substr(s_start, i-s_start+1);
                if (s_dict.count(w)) continue;
                p_dict[c] = w; s_dict[w] = c;
                if (dfs(p, p_start+1, s, i+1, p_dict, s_dict)) return true;
                p_dict.erase(c); s_dict.erase(w);
            }
            return false;
        }
    }
};


int main() {
    Solution s;
    cout << s.wordPatternMatch("aa", "ab") << endl;
    return 0;
}

