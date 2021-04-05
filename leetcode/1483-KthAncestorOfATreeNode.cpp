#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// doubling
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686268/Explanation-with-c%2B%2B-sample-code
class TreeAncestor {
public:
    // ps[i][j] is node j's 2^i-th parent
    vector<int> ps[20];

    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 0; i < 20; ++i) {
            ps[i] = vector<int>(n, -1);
            for (int j = 0; j < n; ++j) {
                if (i == 0) ps[i][j] = parent[j];
                else {
                    int pi1 = ps[i-1][j];
                    if (pi1 != -1) pi1 = ps[i-1][pi1];
                    ps[i][j] = pi1;
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; ++i) {
            if (k & (1<<i)) node = ps[i][node];
            if (node == -1) return node;
        }
        return node;
    }
};

int main() {

}