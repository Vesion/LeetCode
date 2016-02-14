#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

void printList(ListNode* &head) {
    if (head) {
        for (ListNode* p = head; p; p = p->next)
            cout << p->val << "->";
    }
    cout << "NULL" << endl;
    return;
}

ListNode* appendNode(ListNode* head, int x) {
    if (!head)
        head = new ListNode(x);
    else {
        ListNode* p = head;
        while (p->next) p = p->next;
        p->next = new ListNode(x);
    }
    return head;
}

void deleteList(ListNode* &head) {
    if (!head) return;
    while (head) {
        ListNode* p = head->next;
        delete head;
        head = p;
    }
    return;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || !head->next || m == n) return head;

    ListNode dummy(-1); dummy.next = head; // for new head
    ListNode *breakup1 = &dummy, *breakup2; // record breakup point
    n = n - m + 1;
    while (--m) {breakup1 = head; head = head->next;} // head step forward
    breakup2 = head; // breakup1 record left, breakup2 record right

    ListNode *prev = NULL, *next = NULL; // iterator
    while (n--) { // reverse (n-m+1) nodes
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    breakup1->next = prev;
    breakup2->next = head;
    return dummy.next;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 5);
    printList(head);

    head = reverseBetween(head, 1, 5);
    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}
