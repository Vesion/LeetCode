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

// Given a list, rotate the list to the right by k places, where k is non-negative.
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode* p = head;
        for (; p->next; p = p->next) ++len;
        k %= len;
        if (k == 0) return head;

        p->next = head; // connect to a cycle
        for (int i = 0; i < len-k; ++i) p = p->next;
        head = p->next;
        p->next = NULL; // break the cycle
        return head;
    }
};


int main() {
    return 0;
}
