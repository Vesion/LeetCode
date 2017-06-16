#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> m(n+1, 0);
        for (string& w : dict) {
            auto p = s.find(w, 0);
            while (p != string::npos) { 
                m[p]++; m[p+w.size()]--; 
                p = s.find(w, p+1);
            }
        }
        string res;
        int c = 0; bool f = false;
        for (int i = 0; i < n; ++i) {
            c += m[i];
            if (c > 0 && !f) { res += "<b>"; f = true; }
            if (c == 0 && f) { res += "</b>"; f = false; }
            res += s[i];
        }
        if (f) res += "</b>";
        return res;
    }
};


int main() {
    Solution s;
    string t = "aaabbcc";
    vector<string> dict = {"aaa", "aab", "bc"};
    cout << s.addBoldTag(t, dict) << endl;;
    return 0;
}
