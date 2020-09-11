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

// Solution 1 : iterative
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (l1 || l2) {
            if (!l1 || (l1 && l2 && l2->val < l1->val)) {
                cur->next = new ListNode(l2->val);
                l2 = l2->next;
            } else {
                cur->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};

// Solution 2 : recursive, need to modify inputs
class Solution_2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    return 0;
}
