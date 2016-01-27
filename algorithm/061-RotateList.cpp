#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

void printList(ListNode *head) {
    if (!head) {
        cout << "NULL" << endl;
        return;
    }
    for (ListNode *p = head; p; p = p->next)
        cout << p->val << " ";
    cout << "NULL" << endl;
    return;
}

ListNode* appendNode(ListNode *head, int x) {
    if (!head) {
        head = new ListNode(x);
        return head;
    }
    ListNode *p = head;
    while (p->next) p = p->next;
    p->next = new ListNode(x);
    return head;
}

void deleteList(ListNode *&head) {
    if (!head)
        return;
    while(head) {
        ListNode *p = head->next;
        delete head;
        head = p;
    }
    return;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) // if empty, or only one node, return
        return head;
    
    // get k mod len
    ListNode *p = head;
    int len = 1;
    while (p->next) {
        p = p->next;
        len++;
    }
    k = k % len;

    p->next = head; // form a cycle
    for (int i = 0; i < len - k; ++i) // run len-k steps
        p = p->next;
    head = p->next; // new head
    p->next = NULL; // break the cycle
    return head;
}

int main() {
    ListNode *head = new ListNode(1);
    appendNode(head, 2);
    appendNode(head, 3);
    printList(head);

    head = rotateRight(head, 9);
    printList(head);

    deleteList(head);
    printList(head);
}
