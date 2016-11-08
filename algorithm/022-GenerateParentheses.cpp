#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : Catalan recursively
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        if (n == 1) return {"()"};
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            for (string& s1 : generateParenthesis(i))
                for (string& s2 : generateParenthesis(n-i-1))
                    res.push_back(s1 + '(' + s2 + ')');
        }
        return res;
    }
};


// Solution 2 : common dfs
class Solution_2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, 0);
        return res;
    }

    void dfs(vector<string>& res, string path, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        if (left) dfs(res, path+'(', left-1, right+1);
        if (right) dfs(res, path+')', left, right-1);
    }
};



int main() {
    Solution_2 s;
    auto r = s.generateParenthesis(3);
    for (auto& e : r) cout << e << endl;; cout << endl; 
    return 0;
}

