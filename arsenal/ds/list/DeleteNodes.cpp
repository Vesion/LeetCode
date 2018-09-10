#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

// Version 1 : Just given the node to be deleted (no head)
class Version_1 {
public:
    void deleteNode(ListNode* node) {
        if (!node) return;
        ListNode* tmp = node->next;
        *node = *(node->next);
        delete tmp;
    }
};


// Version 2 : Given a value, remove all elements that have value val.
// Solution 1 : iterative
class Solution_1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode dummy(0); dummy.next = head;
        ListNode* p = &dummy;
        while (p && p->next) {
            if (p->next->val == val) p->next = p->next->next;
            else p = p->next;
        }
        return dummy.next;
    }
};


// Solution 2 : recursive
class Solution_2 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};


// Solution 3 : two-level pointers
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode** phead = &head;
        while (*phead) {
            if ((*phead)->val == val) *phead = (*phead)->next;
            else phead = &(*phead)->next;
        }
        return head;
    }
};


int main() {
    return 0;
}

