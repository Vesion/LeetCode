#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string& s, int left, int right) {
    while (left < right && s[left] == s[right]) {
        ++left;
        --right;
    }
    return left >= right;
}

void dfs(vector<vector<string>>& result, vector<string>& path, string &s, int n, int start) {
    if (start == n) {
        result.push_back(path);
        return;
    }
    for (int i = start; i < n; ++i) {
        if (isPalindrome(s, start, i)) {
            path.push_back(s.substr(start, i-start+1));
            dfs(result, path, s, n, i+1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    if (s.empty()) return result;
    vector<string> path;
    dfs(result, path, s, s.size(), 0);
    return result;
}

int main() {
    auto result = partition("aab");
    for (auto & i : result) {
        for (auto & j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
