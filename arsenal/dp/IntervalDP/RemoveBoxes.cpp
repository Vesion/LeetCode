#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : top-down + memoization
class Solution {
public:
    // memo, m[l][r][k] = solution for boxes[l..r] followed by k same color boxes. 
    // Follow does not mean strictly consecutive boxes, for example, [1, 3, 2, 3, 4], 3 can be followed by the other 3 because we can remove 2 first
    int m[100][100][100] = {{{0}}};

    int removeBoxes(vector<int>& boxes) {
        return dfs(boxes, 0, boxes.size()-1, 0);
    }

    int dfs(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (m[l][r][k]) return m[l][r][k];
        m[l][r][k] = dfs(boxes, l, r-1, 0) + (k+1)*(k+1);
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r]) {
                m[l][r][k] = max(m[l][r][k], dfs(boxes, l, i, k+1) + dfs(boxes, i+1, r-1, 0));
            }
        }
        return m[l][r][k];
    }
};


// Solution 2 : top-down + memoization + interval consecutive optimization
class Solution_2 {
public:
    int m[100][100][100];
    int val[100], len[100], segs = 0;

    int removeBoxes(vector<int>& boxes) {
        int i = 0, n = boxes.size();
        while (i < n) {
            int v = boxes[i], l = 0;
            while (i < n && boxes[i] == v) {
                ++i; ++l;
            }
            val[segs] = v;
            len[segs++] = l;
        }
        return dfs(0, segs-1, 0);
    }

    int dfs(int l, int r, int k) {
        if (l > r) return 0;
        if (m[l][r][k]) return m[l][r][k];
        m[l][r][k] = dfs(l, r-1, 0) + (len[r]+k)*(len[r]+k);
        for (int i = l; i < r; ++i) {
            if (val[i] == val[r]) {
                m[l][r][k] = max(m[l][r][k], dfs(l, i, len[r]+k) + dfs(i+1, r-1, 0));
            }
        }
        return m[l][r][k];
    }
};


int main() {
    return 0;
}

