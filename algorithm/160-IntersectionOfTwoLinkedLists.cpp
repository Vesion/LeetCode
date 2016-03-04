#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
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
        cout << "nullptr" << endl;
        return;
    }
    printList(head->next);
}

void deleteList(ListNode* &head) {
    if (!head) return;
    deleteList(head->next);
    delete head;
    head = nullptr;
}

// Solution 1 : use difference of length, O(n) time, O(1) space
ListNode *getIntersectionNode_verbose(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return NULL;

    // pa from headA, pb from headB, go forward until one of them reach NULL
    ListNode *pa = NULL, *pb = NULL;
    for (pa = headA, pb = headB; pa && pb; pa = pa->next, pb = pb->next);

    // figure out which one reach NULL first, if pa, it means that headA is longer than headB.
    // pa go on, get the difference(steps count) of headA's length and headB's
    bool Alonger = false;
    ListNode* p;
    if (pa) { Alonger = true; p = pa; }
    else { Alonger = false; p = pb; }
    int count = 0;
    while (p) {p = p->next; ++count;}
    pa = headA; pb = headB;
    
    // pa go 'count' steps first, then pb goes with pa together, until reach the intersection node, or NULL
    if (Alonger) while (count--) pa = pa->next;
    else while (count--) pb = pb->next;
    for (; pa && pb; pa = pa->next, pb = pb->next) {if (pa == pb) return pa;}
    return NULL;
}


// Solution 2 : same idea as above, but much more concise! orz orz orz
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
        pa = pa ? pa->next : headB;
        pb = pb ? pb->next : headA;
    }
    return pa;
}

int main() {
    ListNode* l1 = nullptr;
    l1 = appendNode(l1, 1);
    l1 = appendNode(l1, 2);
    l1 = appendNode(l1, 3);
    l1 = appendNode(l1, 4);
    l1 = appendNode(l1, 5);

    ListNode* l2 = nullptr;
    l2 = appendNode(l2, 2);
    l2->next = l1->next->next;

    printList(l1);
    printList(l2);

    cout << getIntersectionNode(l1, l2)->val << endl;

    deleteList(l2);
    deleteList(l1);
    return 0;
}
