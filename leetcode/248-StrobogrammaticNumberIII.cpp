#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Based on 247-StrobogrammaticNumberII
class Solution {
public:
    unordered_map<char,char> m = {{'0','0'}, {'1','1'}, {'6','9'}, {'9','6'}, {'8','8'}};

    int strobogrammaticInRange(string low, string high) {
        int m = low.size(), n = high.size();
        int res = 0;
        for (int l = m; l <= n; ++l) {
            if (m < l && l < n) {
                // do math to caculate the count directly
                if (l & 1) res += pow(5, l/2-1) * 4 * 3;  // begin and end cannot be 0, mid cannot be 6 or 9
                else res += pow(5, l/2-1) * 4;  // begin and end cannot be 0
            } else {
                // resort to enumerate
                string path(l, '0');
                res += dfs(0, l-1, path, low, high);
            }
        }
        return res;
    }

    int dfs(int i, int j, string& path, const string& low, const string& high) {
        if (i > j) {
            if (path.size() == low.size() && path < low) return 0;
            if (path.size() == high.size() && path > high) return 0;
            return 1;
        }
        int res = 0;
        for (const auto& p : m) {
            if (i < j && i == 0 && p.first == '0') continue;  // begin and end cannot be 0
            if (i == j && (p.first == '6' || p.first == '9')) continue;  // mid cannot be 6 or 9
            path[i] = p.first;
            path[j] = p.second;
            res += dfs(i+1, j-1, path, low, high);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.strobogrammaticInRange("0", "1680") << endl;
    return 0;
}
