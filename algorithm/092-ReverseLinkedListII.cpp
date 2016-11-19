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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m == n) return head;
        int l = n-m+1;
        ListNode dummy(0); dummy.next = head;
        ListNode *break1 = &dummy;
        while (--m) break1 = break1->next;
        ListNode* break2 = break1->next;

        ListNode *pre = NULL, *cur = break1->next;
        while (l--) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        break1->next = pre;
        break2->next = cur;
        return dummy.next;
    }
};

int main() {
    return 0;
}

