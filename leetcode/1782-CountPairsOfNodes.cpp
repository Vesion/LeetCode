#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The problem can be converted to:
// for a given array A, count pairs of (i, j), i < j, which:
//   A[i] + A[j] - e[i][j] > T
// equals to:
//   (1) A[i] + A[j] > T
//   (2) A[i] + A[j] - e[i][j] < T
//   then (1) - (2)
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> cnt(n + 1), sorted_cnt(n + 1), res;
        vector<unordered_map<int, int>> shared(n + 1);
        for (auto &e : edges) {
            sorted_cnt[e[0]] = cnt[e[0]] = cnt[e[0]] + 1;
            sorted_cnt[e[1]] = cnt[e[1]] = cnt[e[1]] + 1;
            ++shared[min(e[0], e[1])][max(e[0], e[1])];
        }
        sort(begin(sorted_cnt), end(sorted_cnt));
        for (auto &q : queries) {
            int t = 0;
            for (int i = 1, j = n; i < j; ) {
                if (q < sorted_cnt[i] + sorted_cnt[j]) {
                    t += (j-i);
                    --j;
                } else ++i;
            }
            for (auto i = 1; i <= n; ++i)
                for (auto [j, sh_cnt]: shared[i])
                    if (q < cnt[i] + cnt[j] && q + sh_cnt >= cnt[i] + cnt[j])
                        --t;
            res.push_back(t);
        }
        return res;
    }
};


int main() {

}