#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int hand[5][10];
int pairs[5], suit[5];

bool dfs(int depth) {
    if (depth  == 4) {
        int cnt = 0;
        for (int i = 0; i < 3; ++i) if (suit[i]) ++cnt;
        return cnt <= 2;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (hand[i][j] >= 3) {
                hand[i][j] -= 3;
                ++suit[i];
                if (dfs(depth+1)) return true;
                --suit[i];
                hand[i][j] += 3;
            }
            if (j <= 7 && hand[i][j] >= 1 && hand[i][j+1] >= 1 && hand[i][j+2] >= 1) {
                hand[i][j] -= 1;
                hand[i][j+1] -= 1;
                hand[i][j+2] -= 1;
                ++suit[i];
                if (dfs(depth+1)) return true;
                --suit[i];
                hand[i][j+2] += 1;
                hand[i][j+1] += 1;
                hand[i][j] += 1;
            }
        }
    }
    return false;
}

bool rule1() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (hand[i][j] >= 2) {
                ++suit[i];
                hand[i][j] -= 2;
                if (dfs(0)) return true;
                --suit[i];
                hand[i][j] += 2;
            }
        }
    }
    return false;
}

bool rule2() {
    memset(pairs, 0, sizeof pairs);
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= 9; ++j)
            pairs[i] += hand[i][j] / 2;
    return pairs[0]+pairs[1] >= 7 || pairs[1]+pairs[2] >= 7 || pairs[0]+pairs[2] >= 7;
}

int solve(int n) {
    for (int i = 0; i <= n; ++i) {
        if (i > 0) {
            string s; cin >> s;
            ++hand[s[0]-'a'][s[1]-'0'];
        }
        if (rule1() || rule2()) return i;
    }
    return -1;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < 14; ++i) {
        string s; cin >> s;
        ++hand[s[0]-'a'][s[1]-'0'];
    }
    cout << solve(n) << endl;
    return 0;
}
