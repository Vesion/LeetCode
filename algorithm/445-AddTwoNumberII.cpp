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

void print(ListNode* head) {
    if (head) {
        cout << head->val << " ";
        print(head->next);
    }
}

ListNode* append(ListNode* head, int val) {
    if (!head) head = new ListNode(val);
    else head->next = append(head->next, val);
    return head;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        l1 = reverseList(l1), l2 = reverseList(l2);
        ListNode dummy(0);
        ListNode* p = &dummy;
        for (int carry = 0; l1 || l2 || carry; carry /= 10) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry%10);
            p = p->next;
        }
        return reverseList(dummy.next);
    } 

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main() {
    Solution s;
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    l1 = append(l1, 7);
    l1 = append(l1, 2);
    l1 = append(l1, 4);
    l1 = append(l1, 3);
    l2 = append(l2, 5);
    l2 = append(l2, 6);
    l2 = append(l2, 4);

    ListNode* r = s.addTwoNumbers(l1, l2);
    print(r);

    return 0;
}
