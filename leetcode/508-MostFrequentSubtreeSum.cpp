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
        int fre = 0;
        unordered_map<int, int> m;
        postorder(root, fre, m);

        vector<int> res;
        for (auto& p : m) if (p.second == fre) res.push_back(p.first);
        return res;
    }
    
    int postorder(TreeNode* root, int& fre, unordered_map<int,int>& m) {
        if (!root) return 0;
        int left = postorder(root->left, fre, m);
        int right = postorder(root->right, fre, m);
        int sum = left + right + root->val;
        fre = max(fre, ++m[sum]);
        return sum;
    }
};


int main() {
    return 0;
}
