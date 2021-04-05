#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Union find, O(N^2)
class Solution0 {
public:
    int count;
    vector<int> root;

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        count = n;

        for (int i = 0; i < n; ++i) {
            int x0 = stones[i][0], y0 = stones[i][1];
            for (int j = i+1; j < n; ++j) {
                int x1 = stones[j][0], y1 = stones[j][1];
                if (x0 == x1 || y0 == y1) {
                    link(i, j);
                }
            }
        }
        return n - count;
    }

    int find(int x) {
        if (root[x] != x) root[x] = find(root[x]);
        return root[x];
    }
    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            root[ry] = rx;
            --count;
        }
    }
};

// Union find, O(N)
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)
class Solution {
public:
    unordered_map<int,int> root;
    int count = 0;
    int removeStones(vector<vector<int>>& stones) {
        for (const auto& stone : stones) {
            link(stone[0], ~stone[1]);
        }
        return stones.size() - count;
    }
    int find(int x) {
        if (!root.count(x)) {
            root[x] = x;
            ++count;
            return x;
        }
        if (root[x] != x) root[x] = find(root[x]);
        return root[x];
    }
    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            root[ry] = rx;
            --count;
        }
    }
};

int main() {

}
