#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<string>& result, vector<string>& path, string& s, int cur, int steps) {
    if (steps > 4) return;
    if (steps == 4 && cur == s.size()) {
        string r;
        for (auto i : path) r += (i + '.');
        r.pop_back();
        result.push_back(r);
        return;
    }

    int num = 0;
    int start = cur;
    for (int i = cur; i < s.size(); ++i) {
        num = num * 10 + (s[i] - '0');
        if (num <= 255) {
            path.push_back(s.substr(start, i-start+1));
            dfs(result, path, s, i+1, steps+1);
            path.pop_back();
        } else
            break;
        if (num == 0) break; // 0 must not be prefix
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.size() < 4 || s.size() > 12) return result;
    vector<string> path;
    dfs(result, path, s, 0, 0);
    return result;
}

int main() {
    for (auto i : restoreIpAddresses("010010"))
        cout << i << "     ";
    cout << endl;
    return 0;
}
