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

void printList(ListNode* head) {
    if (head) {
        cout << head->val << " ";
        printList(head->next);
    }
}

ListNode* appendList(ListNode* head, int val) {
    if (!head) head = new ListNode(val);
    else head->next = appendList(head->next, val);
    return head;
}

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

void printTree(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

// Solution 1 : first conver list to array, then recursively convert to BST
class Solution_1 {
public:
    TreeNode* generate(vector<int>&nums, int left, int right) {
        if (left >= right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = generate(nums, left, mid);
        node->right = generate(nums, mid+1, right);
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        vector<int> nums;
        for (ListNode* p = head; p; p = p->next) nums.push_back(p->val);
        return generate(nums, 0, nums.size());
    }
};


// Solution 2 : how to do recursion?
class Solution {
public:
    TreeNode* generate(ListNode* &head, int start, int end) {
        if (start >= end) return NULL;
        int mid = start + (end-start)/2;
        TreeNode* left = generate(head, start, mid);
        TreeNode* node = new TreeNode(head->val);
        node->left = left;
        head = head->next;
        node->right = generate(head, mid+1, end);
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        int l = 0;
        for (ListNode* p = head; p; p = p->next) ++l;
        return generate(head, 0, l);
    }
};


int main() {
    Solution s;
    ListNode* head = NULL;
    head = appendList(head, 0);
    head = appendList(head, 1);
    head = appendList(head, 2);
    head = appendList(head, 3);
    head = appendList(head, 4);
    head = appendList(head, 5);
    head = appendList(head, 6);
    printList(head);
    cout << endl;

    TreeNode* root = s.sortedListToBST(head);
    printTree(root);
    cout << endl;

    return 0;
}
