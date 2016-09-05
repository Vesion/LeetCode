#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : heap, very similar to 373-FindKPairsWithSmallestSums
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();

        auto cmp = [&matrix] (const pair<int, int>& p1, const pair<int, int>& p2) {
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        q.emplace(0, 0);
        int result;
        while (k-- && !q.empty()) {
            auto t = q.top(); q.pop();
            result = matrix[t.first][t.second];
            if (t.first+1 < m) 
                q.emplace(t.first+1, t.second);
            if (t.first == 0 && t.second+1 < n) 
                q.emplace(t.first, t.second+1); // !
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = { 
        { 1,  5,  9 },
        //{ 10, 11, 13 },
        //{ 12, 13, 15 },
    };
    cout << s.kthSmallest(matrix, 3) <<endl;;
    return 0;
}
