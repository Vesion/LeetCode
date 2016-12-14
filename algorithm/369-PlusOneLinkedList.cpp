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
    ListNode* plusOne(ListNode* head) {
        if (dfs(head)) {
            ListNode* newhead = new ListNode(1);
            newhead->next = head;
            return newhead;
        } else return head;
    }
    
    int dfs(ListNode* head) {
        if (!head) return 1;
        int carry = dfs(head->next);
        int sum = head->val + carry;
        head->val = sum % 10;
        return sum / 10;
    }
};


int main() {
    Solution s;
    return 0;
}
