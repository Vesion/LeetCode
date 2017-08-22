#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> g;
string s;
int len;
string res;

bool dfs(int cur, int pre, bool below) {
    if (cur == len) return true;
    if (below) {
        while (cur < len) res[cur++] = g[pre].back()+'0';
        return true;
    } else {
        int i = s[cur]-'0';
        for (int k = g[pre].size()-1; k >= 0; --k) {
            int j = g[pre][k];
            if (j <= i) {
                res[cur] = j+'0';
                if (dfs(cur+1, j, j < i)) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    g = {
        {0},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 2, 3, 5, 6, 8, 9},
        {3, 6, 9},
        {0, 4, 5, 6, 7, 8, 9},
        {0, 5, 6, 8, 9},
        {6, 9},
        {0, 7, 8, 9},
        {0, 8, 9},
        {9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    };


    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        len = s.size();
        res.resize(len);
        dfs(0, 10, false);
        cout << res << endl;
    }
    return 0;
}
