#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* appendNode(ListNode* head, int x) {
    if (!head) head = new ListNode(x);
    else head->next = appendNode(head->next, x);
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

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* second = head->next; // the head of second part
    ListNode *odd = head, *even = second;
    while (odd->next && even->next) {
        odd->next = even->next;
        even->next = even->next->next;
        odd = odd->next;
        even = odd->next;
    }
    odd->next = second;
    return head;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 5);
    head = appendNode(head, 6);
    printList(head);

    head = oddEvenList(head);
    printList(head);

    deleteList(head);
    return 0;
}
