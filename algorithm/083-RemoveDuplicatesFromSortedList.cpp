#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;


void printList(ListNode* &head) {
    if (!head) {
        cout << "empty list" << endl;
    } else {
        for (ListNode* p = head; p; p = p->next)
            cout << p->val << " ";
        cout << endl;
    }
}

ListNode* appendNode(ListNode* head, int x) {
    if (!head) {
        cout << "new" << endl;
        head = new ListNode(x);
    } else {
        ListNode* p = head;
        while (p->next) p = p->next;
        p->next = new ListNode(x);
    }
    return head;
}

void deleteList(ListNode* &head) { // use reference& to guarantee return NULL head
    if (!head) return;
    while(head) {
        ListNode *p = head->next;
        delete head;
        head = p;
    }
    return; // here head MUST be NULL
}

// similiar to No.026 and 080
ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode *cur = head->next, *prev = head;
    while (cur) {
        if (cur->val != prev->val) {
            prev = prev->next;
            prev->val = cur->val;
        }
        cur = cur->next;
    } 
    deleteList(prev->next);
    return head;
}

int main() {
    ListNode* head = NULL;

    head = appendNode(head, 1);
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 4);
    printList(head);

    head = deleteDuplicates(head);
    printList(head);

    deleteList(head);
    printList(head);

    return 0;
}
