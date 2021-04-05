#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// straight forward, min-heap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        using S = tuple<int,vector<int>>;
        priority_queue<S, vector<S>, greater<S>> pq;
        int sum = 0;
        for (int i = 0; i < m; ++i) sum += mat[i][0];
        vector<int> id(m, 0);
        set<vector<int>> vis; vis.insert(id);
        pq.push({sum, id});

        while (k--) {
            auto [ts, ti] = pq.top(); pq.pop();
            sum = ts;
            for (int i = 0; i < m; ++i) {
                int j = ti[i];
                if (j+1 < n) {
                    auto nti = ti; nti[i] = j+1;
                    if (vis.count(nti)) continue;
                    int nts = ts - mat[i][j] + mat[i][j+1];
                    pq.push({nts, nti});
                    vis.insert(nti);
                }
            }
        }
        return sum;
    }
};


// generate sums row by row, keep only k sums
// k is small(200) in this question
// O(m*n*k*logk)
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> row = mat[0];
        for(int i = 1; i < m; ++i) {
            vector<int> nr;
            for(int j = 0; j < n; ++j) {
                for(int num : row) {
                    nr.push_back(mat[i][j] + num);
                }
            }
            int l = nr.size();
            sort(nr.begin(), nr.end());
            nr.resize(min(k, l));
            row.swap(nr);
        }
        return row[k-1];
    }
};


// binary search
class Solution2 {
public:
    const int kMin = 1, kMax = 5000;
    int m, n;

    int kthSmallest(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        int left = m, right = m*kMax;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int c = count(mat, 0, 0, mid, k);
            if (c >= k) right = mid-1;
            else left = mid+1;
        }
        return left;
    }

    // count arrays picked with sum <= target
    int count(const vector<vector<int>>& mat, int i, int sum, int target, int k) {
        if (sum > target) return 0;
        if (i == m) return 1;
        int res = 0;
        for (int j = 0; j < n; ++j) {
            int c = count(mat, i+1, sum+mat[i][j], target, k-res);
            if (c == 0) break;
            res += c;
            if (res > k) break;
        }
        return res;
    }
};

int main() {
}