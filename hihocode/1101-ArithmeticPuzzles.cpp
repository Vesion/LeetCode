#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string addStrings(string& num1, string& num2) {
    string result;
    for (int i = num1.size()-1, j = num2.size()-1, carry = 0; i >= 0 || j >= 0 || carry; carry /= 10) {
        if (i >= 0) carry += num1[i--]-'0';
        if (j >= 0) carry += num2[j--]-'0';
        result = to_string(carry%10) + result;
    }
    return result;
}

int T;
string S; // source
string R; // result
char M[26]; // alphabets
bool V[10]; // visited digits
int C; // number of different letters

bool eval() {
    R = S;
    int i = 0, j = 0;
    string left = "", right = "";
    bool f = false;
    while (j < (int)R.size()) {
        if (R[j] >= 'A' && R[j] <= 'Z') R[j] = M[R[j]-'A'];
        else {
            string tmp = R.substr(i, j-i);
            if (tmp.size() > 1 && tmp[0] == '0') return false;
            if (!f) {
                left = addStrings(left, tmp);
                i = j+1;
            } else {
                right = addStrings(right, tmp);
                i = j+1;
            }
            if (R[j] == '=') f = true;
        }
        ++j;
    }
    string tmp = R.substr(i, j-i);
    if (tmp.size() > 1 && tmp[0] == '0') return false;
    right = addStrings(right, tmp);
    return left == right;
}

bool dfs(int c) {
    if (c == C) return eval();
    for (int i = 0; i < 26; ++i) {
        if (M[i] == 1) {
            for (int j = 0; j <= 9; ++j) {
                if (!V[j]) {
                    M[i] = '0' + j;
                    V[j] = true;
                    if (dfs(c+1)) return true;
                    M[i] = 1;
                    V[j] = false;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> S;
        memset(M, 0, sizeof M);
        memset(V, false, sizeof V);
        C = 0;
        for (char c : S) {
            if (c >= 'A' && c <= 'Z' && M[c-'A'] == 0) {
                M[c-'A'] = 1;
                ++C;
            }
        }
        if (C <= 10 && dfs(0)) cout << R << endl;
        else cout << "No Solution" << endl;
    }
    return 0;
}
