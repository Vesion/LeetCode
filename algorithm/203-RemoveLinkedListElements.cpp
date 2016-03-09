#include <iostream>
#include <vector>
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
    if (!head)
        cout << "NULL" << endl;
    else {
        cout << head->val << " ";
        printList(head->next);
    }
}

void deleteList(ListNode* &head) {
    if (!head) return;
    deleteList(head->next);
    delete head;
    head = NULL;
}

// Solution 1 : iterative, up-down
ListNode* removeElements_it(ListNode* head, int val) {
    if (!head) return NULL;
    ListNode dummy(0); dummy.next = head;
    ListNode *prev = &dummy, *cur = head;
    while (cur) {
        if (cur->val == val) {
            prev->next = cur->next;
            delete cur;
            cur = cur->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy.next;
}


// Solution 2 : recursive, bottom-up, skillful
ListNode* removeElements_re(ListNode* head, int val) {
    if (!head) return NULL;
    head->next = removeElements_re(head->next, val);
    return head->val == val ? head->next : head;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 2);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 3);
    head = appendNode(head, 2);
    head = appendNode(head, 2);
    printList(head);

    //head = removeElements_it(head, 2);
    head = removeElements_re(head, 2);
    printList(head);
    deleteList(head);
    printList(head);
    return 0;
}
