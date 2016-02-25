#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

// a hard dfs+greedy problem
// 本题不同于112, 113，本题的路径是任意结点到任意结点，就有点类似于053中“求最大连续子段和”
// 不过053中是数组，所以只有一个方向，而本题是树，有两个方向，而且数组可以顺序遍历，而树不能，只能用dfs来遍历
// 从根结点出发，向左、右两个方向遍历，递归算出左右子树的结果left和right，如果left大于0，那么对后续结果是有利的，要加上left，right同样如此
// 维护一个全局变量，用来实时更新最大和
//
int dfs(TreeNode* root, int& result) {
    if (!root) return 0;
    int left = dfs(root->left, result);
    int right = dfs(root->right, result);
    left = max(0, left);
    right = max(0, right);
    result = max(result, root->val + left + right);
    return root->val + max(left, right); // 注意这里只能返回left或right中的一个，因为在递归中，只能向父结点返回，不可能存在L->root->R或R->root->L这样的递归方向
}

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;    
    dfs(root, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << maxPathSum(root) << endl;

    deleteTree(root);
    return 0;
}
