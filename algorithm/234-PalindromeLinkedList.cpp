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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        mid = reverse(mid);
        while (mid) {
            if (head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};

int main() {
    Solution s;
    return 0;
}
