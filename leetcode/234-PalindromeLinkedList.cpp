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
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next; // regardless of even or odd length
        second = reverse(second);
        while (second) { // because second half may be one node shorter than first half
            if (head->val != second->val) return false;
            head = head->next;
            second = second->next;
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
    return 0;
}
