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

// merge sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
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
};

int main() {
    Solution s;
    return 0;
}

