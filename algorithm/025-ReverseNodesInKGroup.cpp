#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

void printList(ListNode* &head) {
    if (!head)
        cout << "empty list" << endl;
    else {
        for (ListNode* p = head; p; p = p->next)
            cout << p->val << " ";
        cout << "NULL" << endl;
    }
    return;
}

ListNode* appendNode(ListNode* head, int x) {
    if (!head)
        head = new ListNode(x);
    else {
        ListNode *p = head;
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

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) return head;
    ListNode dummy(0);
    dummy.next = head;
    ListNode *front = head, *behind = &dummy;
    while (front) {
        ListNode* next_behind = front; // record next behind

        int ck = k-1;
        while (front && ck--)
            front = front->next;
        if (!front) break;

        ListNode* next_front = front->next; // record next front
        
        ListNode* prev = behind->next;
        ListNode* cur = prev->next;
        ListNode *next;
        while (prev != front) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        behind->next = front;
        next_behind->next = next_front;

        behind = next_behind;
        front = next_front;
    }
    return dummy.next;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 5);
    head = appendNode(head, 6);
    head = appendNode(head, 7);
    head = appendNode(head, 8);
    head = appendNode(head, 9);
    head = appendNode(head, 10);
    printList(head);

    head = reverseKGroup(head, 11);
    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}
