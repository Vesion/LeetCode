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
            cout << p->val << " ";
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

// Solution 1 : reverse iteratively
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *prev = NULL, *tmp = NULL;
    while (head) {
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}

// Solution 2 : reverse recursively, top down
ListNode* reverseList_topdown(ListNode* head, ListNode* prev = NULL) {
    if (!head) return prev;
    ListNode* tmp = head->next;
    head->next = prev;
    return reverseList_topdown(tmp, head); // tail recursive, could be converted to iterative by compiler
}

// Solution 3 : reverse recursively, bottom up, skillful
ListNode* reverseList_bottomup(ListNode* head) {
    if (!head || !head->next) return head;

    //Assume we get a reverse list in rem nodes other than head.    
    ListNode* rem=reverseList_bottomup(head->next);

    //now head should be added to the end of rem's list. 
    // the last node of rem's list is same as head's next.
    // so point it head.
    head->next->next=head;

    // point head to null to mark the end.
    head->next= NULL;
    return rem;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    printList(head);

    head = reverseList(head);
    printList(head);
    head = reverseList_topdown(head);
    printList(head);
    head = reverseList_bottomup(head);
    printList(head);
    
    deleteList(head);
    printList(head);
    return 0;
}
