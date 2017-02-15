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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        fast = reverse(fast);
        slow = head;
        
        while (fast) {
            ListNode* next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = next;
        }
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
