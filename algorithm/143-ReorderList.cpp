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

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *prev = NULL; // the end after reversing
    while (head) {
        ListNode* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

// firstly reverse the second half part, then link it with first half part
void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* first = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next; 
        head = head->next;
    }
    ListNode* second = head->next;
    head->next = NULL;
    second = reverseList(second);

    while (second) {
        ListNode* temp = second->next;
        second->next = first->next;
        first->next = second;
        first = first->next->next;
        second = temp;
    }
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    printList(head);

    reorderList(head);
    printList(head);

    deleteList(head);
    printList(head);

    return 0;
}
