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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode small(0); ListNode* sp = &small;
        ListNode large(0); ListNode* lp = &large;
        for (ListNode* p = head; p; p = p->next) {
            if (p->val < x) {
                sp->next = p;
                sp = sp->next;
            } else if (p->val >= x) {
                lp->next = p;
                lp = lp->next;
            }
        }
        sp->next = large.next;
        lp->next = NULL;
        return small.next;
    }
};

int main() {
    Solution s;
    return 0;
}

