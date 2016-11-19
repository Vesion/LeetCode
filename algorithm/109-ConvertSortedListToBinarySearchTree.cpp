#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p; p = p->next) ++len;
        return build(head, 0, len);
    }

    TreeNode* build(ListNode*& head, int start, int end) {
        if (start == end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode* left = build(head, start, mid);
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = build(head, mid+1, end);
        return root;
    }
};

int main() {
    Solution s;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(1);
    TreeNode* root = s.sortedListToBST(head);
    cout << root->val << " " << root->left->val << endl;
    return 0;
}

