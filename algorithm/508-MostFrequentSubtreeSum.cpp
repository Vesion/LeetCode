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

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        int fre = 0;
        dfs(root, m, fre);
        vector<int> res;
        for (auto& p : m) if (p.second == fre) res.push_back(p.first);
        return res;
    }
    
    int dfs(TreeNode* root, unordered_map<int, int>& m, int& fre) {
        if (!root) return 0;
        int left = dfs(root->left, m, fre);
        int right = dfs(root->right, m, fre);
        int sum = left + right + root->val;
        fre = max(fre, ++m[sum]);
        return sum;
    }
};


int main() {
    return 0;
}
