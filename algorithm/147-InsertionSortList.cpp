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
            if (cur->val >= pre->val) {
                pre = cur;
                cur = cur->next;
            } else {
                pre->next = cur->next; // break cur node
                for (ListNode* p1 = &dummy, *p2 = dummy.next; p1 != pre; p1 = p2, p2 = p2->next) { // find the insertion position
                    if (p2->val > cur->val) {
                        p1->next = cur;
                        cur->next = p2;
                        break;
                    }
                }
                cur = pre->next;
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution s;
    return 0;
}

