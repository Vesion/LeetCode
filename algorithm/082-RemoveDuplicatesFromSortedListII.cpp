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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode dummy(0); dummy.next = head;
        ListNode* r = &dummy;
        ListNode* p = head;
        while (p) {
            if (p->next && p->val == p->next->val) { // if find duplicates, skip them
                int v = p->val;
                while (p && p->val == v) p = p->next;
                continue;
            } else {
                r->next = p;
                r = r->next;
                p = p->next;
            }
        }
        r->next = NULL;
        return dummy.next;
    }
};

int main() {
    Solution s;
    return 0;
}

