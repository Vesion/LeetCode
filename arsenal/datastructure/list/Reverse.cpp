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

// Version 1 : reverse whole list
// Solution 1 : iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};


// Solution 2 : recursive
class Solution_2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};


// Version 2 : swap in pairs
class Solution_2_2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newhead = head->next;
        head->next = swapPairs(newhead->next);
        newhead->next = head;
        return newhead;
    }
};


// Version 3 : reverse in k group
class Solution_3_2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode *p = head;
        int ck = k;
        while (ck--) {
            if (!p) return head;
            p = p->next;
        }
        ListNode* newhead = reverse(head, k);
        head->next = reverseKGroup(p, k);
        return newhead;
    }

    ListNode* reverse(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* newhead = reverse(head->next, k-1);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};


int main() {
    return 0;
}


