#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* appendNode(ListNode* head, int x) {
    if (!head) {
        head = new ListNode(x);
        return head;
    }
    head->next = appendNode(head->next, x);
    return head;
}

void printList(ListNode* head) {
    if (head)
        cout << head->val << " ";
    else {
        cout << "NULL" << endl;
        return;
    }
    printList(head->next);
}

void deleteList(ListNode* &head) {
    if (!head) return;
    deleteList(head->next);
    delete head;
    head = NULL;
}

ListNode* insertionSortList(ListNode* head) {
    if (!head) return NULL;
    ListNode dummy(-1);
    dummy.next = head;
    for (ListNode* i = head; i && i->next; ) {
        ListNode* cur = i->next;
        if (cur->val >= i->val) { // do not need to insert
            i = i->next; // process next one
            continue; 
        }
        // cur must be smaller than some node before
        for (ListNode* ins = &dummy; ins->next; ins = ins->next) {
            if (cur->val < ins->next->val) { // find that ins->next bigger than cur
                i->next = cur->next; // before insertion, put i to cur->next
                cur->next = ins->next; // break cur
                ins->next = cur; // break ins
                break;
            }
        }
    }
    return dummy.next;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    printList(head);

    head = insertionSortList(head);
    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}
