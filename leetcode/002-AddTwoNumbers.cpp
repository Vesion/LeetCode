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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        for (int carry = 0; l1 || l2 || carry; carry /= 10) {
            if (l1) { carry += l1->val; l1 = l1->next; }
            if (l2) { carry += l2->val; l2 = l2->next; }
            head->next = new ListNode(carry%10);
            head = head->next;
        }
        return dummy.next;
    }
};

int main() {
    return 0;
}
