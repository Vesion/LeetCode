#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Solution 1 : tree dp, O(n)
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m; // {sum from root to current node, its occur times}
        m[0] = 1;
        return dfs(root, 0, sum, m);
    }

    int dfs(TreeNode* root, int sum, int target, unordered_map<int, int>& m) {
        if (!root) return 0;
        sum += root->val;
        int res = m[sum-target]; // find all valid paths in O(1)

        m[sum]++;
        res += dfs(root->left, sum, target, m) + dfs(root->right, sum, target, m);
        m[sum]--;
        return res;
    }
};


// Solution 2 : count from every node, O(n^2)
class Solution_2 {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int count(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = 0;
        if (root->val == sum) ++res;
        res += count(root->left, sum-root->val);
        res += count(root->right, sum-root->val);
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}

