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

// Solution 1 : stack, iterative
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> st;
        for (ListNode* cur = head; cur; cur = cur->next) st.push(cur);
        st.top()->val += 1;
        int carry = 0;
        while (!st.empty()) {
            ListNode* t = st.top(); st.pop();
            carry += t->val;
            t->val = carry%10;
            carry /= 10;
        }
        if (carry) {
            ListNode* newhead = new ListNode(carry);
            newhead->next = head;
            return newhead;
        }
        else return head;
    }
};


// Solution 2 : recursive
class Solution_2 {
public:
    ListNode* plusOne(ListNode* head) {
        int carry = dfs(head);
        if (carry) {
            ListNode* newhead = new ListNode(carry);
            newhead->next = head;
            return newhead;
        }
        else return head;
    }

    int dfs(ListNode* head) {
        if (!head) return 1;
        int carry = dfs(head->next);
        if (carry == 0) return 0;
        carry += head->val;
        head->val = carry%10;
        return carry/10;
    }
};


int main() {
    return 0;
}
