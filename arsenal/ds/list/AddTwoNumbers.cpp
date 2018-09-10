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


// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

// reverse is trivial, we shouldn't modify l1 and l2
// so we must calculate bottom-up, i.e. stack or recursive

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


int main() {
    return 0;
}

