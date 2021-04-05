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


// Version 1 : Given a sorted linked list, delete all duplicates such that each element appear only once.
//      e.g. given 1->1->2, return 1->2.

// Solution 1 : iterative
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p1 = head, *p2 = head;
        while (p2) {
            if (p1->val != p2->val) {
                p1->next = p2;
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        p1->next = NULL;
        return head;
    }
};


// Solution 2 :recursive
class Solution_2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};


// Version 2 : Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//      e.g. given 1->2->3->3->4->4->5, return 1->2->5.
//
class Solution_22 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode dummy(0); dummy.next = head;
        ListNode *p1 = &dummy, *p2 = head;
        while (p2) {
            if (p2->next && p2->val == p2->next->val) { // if find duplicates, skip all of them
                int val = p2->val;
                while (p2 && p2->val == val) p2 = p2->next;
                continue;
            }
            p1->next = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = NULL;
        return dummy.next;
    }
};

int main() {
    return 0;
}

