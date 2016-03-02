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

// Solution 1 : merge sort, O(nlgn) time, O(nlgn) space (due to recursion)
// use 021-MergeTwoSortedList
ListNode* mergeTwoLists(ListNode *p1, ListNode *p2) {
    if (!p1) return p2;
    if (!p2) return p1;
    ListNode ph(-1);
    ListNode *p = &ph;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1) p->next = p1;
    if (p2) p->next = p2;
    return ph.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    // use fast-slow pointer to find intermediate position
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode* left = sortList(head);
    ListNode* right = sortList(fast);
    return mergeTwoLists(left, right);
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    printList(head);

    head = sortList(head);
    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}

