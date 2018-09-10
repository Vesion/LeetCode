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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0); dummy.next = head;
        ListNode *pre = head, *cur = head->next;
        while (cur) {
            if (cur->val >= pre->val) { // skip all increasing sequence
                pre = cur;
                cur = cur->next;
            } else {
                pre->next = cur->next;
                ListNode* p = &dummy;
                while (cur->val >= p->next->val) p = p->next; // find the insertion position
                cur->next = p->next;
                p->next = cur;
                cur = pre->next;
                
            }
        }
        return dummy.next;
    }
};


int main() {
    return 0;
}

