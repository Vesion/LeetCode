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

// Solution 1 : recursive
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* new_next = swapPairs(head->next->next);
        ListNode* next = head->next;
        next->next = head;
        head->next = new_next;
        return next;
    }
};

// Solution 2 : iterative
class Solution_2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0); dummy.next = head;
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next) {
            ListNode* first = cur->next;
            ListNode* second = cur->next->next;
            ListNode* third = cur->next->next->next;
            cur->next = second;
            second->next = first;
            first->next = third;
            cur = first;
        }
        return dummy.next;
    }
};

// Solution 3 : use two-level-pointer
class Solution_3 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b; // think about how this work
            pp = &(a->next);
        }
        return head;
    }
};

int main() {
    return 0;
}

