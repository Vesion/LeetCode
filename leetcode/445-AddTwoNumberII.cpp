#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

// reverse is trivial, we shouldn't modify l1 and l2
// so we must calculate bottom-up, i.e. stack or recursive


// Solution 1 : stack
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        stack<int> s1, s2;
        for (ListNode* p = l1; p; p = p->next) s1.push(p->val);
        for (ListNode* p = l2; p; p = p->next) s2.push(p->val);
        
        ListNode* cur = NULL;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            if (!s1.empty()) { carry += s1.top(); s1.pop(); }
            if (!s2.empty()) { carry += s2.top(); s2.pop(); }
            ListNode* pre = new ListNode(carry%10);
            pre->next = cur;
            cur = pre;
            carry /=10;
        }
        return cur;
    }
};


// Solution 2 : recursive
class Solution_2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0;
        for (ListNode* p1 = l1; p1; p1 = p1->next) ++n1;
        for (ListNode* p2 = l2; p2; p2 = p2->next) ++n2;
        if (n1 > n2) return addTwoNumbers(l2, l1);
        ListNode dummy(0);
        ListNode* head = &dummy;
        while (n2-- != n1) {
            head->next = new ListNode(l2->val);
            l2 = l2->next;
            head = head->next;
        }
        while (n1--) {
            head->next = new ListNode(l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
            head = head->next;
        }
        int carry = 0;
        dummy.next = split(dummy.next, carry);
        if (carry) {
            ListNode* p = new ListNode(carry);
            p->next = dummy.next;
            dummy.next = p;
        }
        return dummy.next;
    }

    ListNode* split(ListNode* head, int& carry) {
        if (!head) return head;
        head->next = split(head->next, carry);
        carry += head->val;
        head->val = carry%10;
        carry /= 10;
        return head;
    }
};


int main() {
    return 0;
}
