#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    } else cout << "NULL" << endl;
}

void deleteList(ListNode* &head) {
    if (head) {
        deleteList(head->next);
        delete head;
        head = NULL;
    }
}


// Solution 1 : iteratively set this node's val by its next node's val
void deleteNode_val(ListNode* node) {
    ListNode* pre;
    while (node->next) {
        node->val = node->next->val;
        pre = node;
        node = node->next;
    }
    delete pre->next;
    pre->next = NULL;
}


// Solution 2 : actually, :)
void deleteNode(ListNode* node) {
    ListNode* temp = node->next;
    *node = *temp;
    delete temp;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    printList(head);

    deleteNode(head->next->next);
    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}
