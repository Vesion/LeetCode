#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    // use array instead of unordered_map
    vector<int> first = {'0', '1', '8', '6', '9'};
    vector<int> second = {'0', '1', '8', '9', '6'};

    vector<string> findStrobogrammatic(int n) {
        if (n == 0) return {};
        if (n == 1) return {"0", "1", "8"};
        vector<string> res;
        string path(n, '0');
        dfs(0, n-1, res, path);
        return res;
    }

    void dfs(int start, int end, vector<string>& res, string& path) {
        if (start > end) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < 5; ++i) {
            if (start == end && i >= 3) break; // the middle one cannot be 6 or 9
            if (start == 0 && i == 0) continue; // first digit cannot be 0
            path[start] = first[i];
            path[end] = second[i];
            dfs(start+1, end-1, res, path);
        }
    }
};

int main() {
    Solution s;
    auto r = s.findStrobogrammatic(3);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
