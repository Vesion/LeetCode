#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        vector<int> m(n+1, 0);
        for (const string& w : words) {
            int k = s.find(w);
            while (k != string::npos) {
                ++m[k]; --m[k+w.size()];
                k = s.find(w, k+1);
            }
        }

        string res;
        int c = 0;
        bool bold = false;
        for (int i = 0; i < n; ++i) {
            c += m[i];
            if (c > 0 && !bold) {
                res += "<b>";
                bold = true;
            } else if (c == 0 && bold) {
                res += "</b>";
                bold = false;
            }
            res += s[i];
        }
        if (bold) res += "</b>";
        return res;
    }
};

int main() {
}
