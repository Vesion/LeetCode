#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // check cycle
        vis.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0 && !dfs(i, leftChild, rightChild)) return false;
        }

        // check no node has more than one parents
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        for (int i = 0; i < n; ++i) {
            int left = leftChild[i], right = rightChild[i];
            if (left != -1) {
                if (root[left] != left) return false;
                root[left] = i;
            }
            if (right != -1) {
                if (root[right] != right) return false;
                root[right] = i;
            }
        }

        // check only one tree
        int x = find(0);
        for (int i = 1; i < n; ++i) if (find(i) != x) return false;
        return true;
    }

    vector<int> vis;
    bool dfs(int i, const vector<int>& lefts, const vector<int>& rights) {
        if (vis[i] == 2) return true;
        vis[i] = 1;
        int left = lefts[i], right = rights[i];
        if (left != -1 && (vis[left] == 1 || !dfs(left, lefts, rights))) return false;
        if (right != -1 && (vis[right] == 1 || !dfs(right, lefts, rights))) return false;
        vis[i] = 2;
        return true;
    }

    vector<int> root;
    int find(int x) {
        if (root[x] != x) root[x] = find(root[x]);
        return root[x];
    }
};

int main() {

}
