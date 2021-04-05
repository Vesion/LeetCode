#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Brute-force, TLE
class Solution0 {
public:
    int minCameraCover(TreeNode* root) {
        return dfs(root, false, false);
    }

    // camera is if root has a camera
    // monitor is if root has been monitored by its parent
    int dfs(TreeNode* root, bool camera, bool monitor) {
        if (!root) return 0;
        if (camera) {
            return 1 + dfs(root->left, false, true) + dfs(root->right, false, true);
        }
        if (monitor) {
            int cam = 1 + dfs(root->left, false, true) + dfs(root->right, false, true);
            int nocam = dfs(root->left, false, false) + dfs(root->right, false, false);
            return min(cam, nocam);
        }
        int res = 1 + dfs(root->left, false, true) + dfs(root->right, false, true);
        if (root->left) res = min(res, dfs(root->left, true, false) + dfs(root->right, false, false));
        if (root->right) res = min(res, dfs(root->left, false, false) + dfs(root->right, true, false));
        return res;
    }
};


// Greedy
class Solution {
public:
    int res = 0;
    enum S {
        kNoCamera = 0,  // no camera on this node, and not be covered
        kCamera = 1,  // install camera on this node
        kCovered = 2,  // no camera on this node, but be covered
    };
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == kNoCamera) ++res;
        return res;
    }

    S dfs(TreeNode* root) {
        if (!root) return kCovered;
        S l = dfs(root->left);
        S r = dfs(root->right);
        // anyone of children doesn't have camera and not be covered
        if (l == kNoCamera || r == kNoCamera) {
            ++res;
            return kCamera;
        }
        // anyone of children has camera
        if (l == kCamera || r == kCamera) {
            return kCovered;
        }
        // both of children don't have camera but be covered
        return kNoCamera;
    }
};

int main() {

}
