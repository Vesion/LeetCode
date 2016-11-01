#include <iostream>
#include <vector>
using namespace std;

/* LIST */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteList(ListNode* &head) {
    if (!head) return;
    deleteList(head->next);
    delete head;
    head = NULL;
}

ListNode* appendNode(ListNode* head, int x) {
    if (!head)
        head = new ListNode(x);
    else
        head->next = appendNode(head->next, x);
    return head;
}

void printList(ListNode* head) {
    if (head) {
        cout << head->val << " ";
        printList(head->next);
    } else {
        cout << "NULL" << endl;
    }
}

/* TREE */
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

void printPreorder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// similiar to 108-ConvertSortedArrayToBinarySearchTree


// Solution 1 : top-down, O(nlgn) time
// find mid every time, but the difference is that list cannot access mid element in O(1) time, but in O(n) time, so totally need O(nlgn) time
// ugly performance, don't implement here


// Solution 2 : use O(n) array to store list's vals, then same to array's solution
// O(n) time, O(n) space, don't implement here


// Solution 3 : inorder traversal, O(n)
// refer to others, very skillful
TreeNode* build(ListNode* &list, int start, int end) {
    if (start >= end) return NULL;
    int mid = start + (end-start)/2;
    TreeNode* left = build(list, start, mid); // build left-child tree from bottom to up
    TreeNode* parent = new TreeNode(list->val); // new self
    parent->left = left;
    list = list->next;
    parent->right = build(list, mid+1, end); // build right-child tree from top to down
    return parent;
}

TreeNode* sortedListToBST(ListNode* head) {
    int len = 0;
    for (ListNode* p = head; p; p=p->next) len++;
    return build(head, 0, len);
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 5);
    printList(head);

    TreeNode* root = sortedListToBST(head);
    printPreorder(root);

    deleteTree(root);
    deleteList(head);
    return 0;
}

