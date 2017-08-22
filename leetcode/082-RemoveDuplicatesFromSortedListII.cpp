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
