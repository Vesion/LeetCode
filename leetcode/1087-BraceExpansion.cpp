#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> res;

    vector<string> expand(string s) {
        string path;
        dfs(s, 0, path);
        return res;
    }

    void dfs(const string& s, int start, string& path) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        if (s[start] != '{') {
            path += s[start];
            dfs(s, start+1, path);
            path.pop_back();
            return;
        }
        vector<char> t;
        int i;
        for (i = start+1; s[i] != '}'; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') t.push_back(s[i]);
        }
        sort(t.begin(), t.end());
        for (char c : t) {
            path += c;
            dfs(s, i+1, path);
            path.pop_back();
        }
    }
};

int main() {

}
