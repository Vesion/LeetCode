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
        ListNode *p = &dummy;
        while (--m) p = p->next;
        ListNode* tail = p->next;

        ListNode* cur = p->next;
        ListNode *pre = NULL;
        while (l--) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        p->next = pre;
        tail->next = cur;
        return dummy.next;
    }
};


int main() {
    return 0;
}
