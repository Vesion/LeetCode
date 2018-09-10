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


// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        int len = 0;
        for (ListNode* p = head; p; p = p->next) ++len;
        return convert(head, 0, len);
    }
    
    // inorder traversal, the head argument must be reference so that we can solve in one pass
    TreeNode* convert(ListNode*& head, int start, int end) {
        if (start == end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode* left = convert(head, start, mid);

        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        TreeNode* right = convert(head, mid+1, end);
        root->left = left;
        root->right = right;
        return root;
    }
};


int main() {
    return 0;
}

