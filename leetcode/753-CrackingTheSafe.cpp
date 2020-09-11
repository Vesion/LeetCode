#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;

// https://en.wikipedia.org/wiki/De_Bruijn_sequence
class Solution {
public:
    unordered_set<string> visit;

    string crackSafe(int n, int k) {
        string res(n, '0');
        visit.insert(res);
        const int target = pow(k, n);
        dfs(n, k, target, res);
        return res;
    }

    bool dfs(const int n, const int k, const int t, string& res) {
        if (visit.size() == t) return true;

        string suf = res.substr(res.size()-n+1);
        for (int i = 0; i < k; ++i) {
            suf.push_back('0' + i);
            res.push_back('0' + i);
            if (!visit.count(suf)) {
                visit.insert(suf);
                if (dfs(n, k, t, res)) return true;
                visit.erase(suf);
            }
            suf.pop_back();
            res.pop_back();
        }
        return false;
    }
};


int main() {
  Solution s;
  cout << s.crackSafe(2, 10) << endl;
  return 0;
}
