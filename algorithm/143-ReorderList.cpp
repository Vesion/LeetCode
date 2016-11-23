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

        // split into two halves
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;

        // reverse the second half
        mid = reverseList(mid);

        // chain them cross
        while (head && mid) {
            ListNode* next = mid->next;
            mid->next = head->next;
            head->next = mid;
            head = mid->next;
            mid = next;
        } 
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

int main() {
    Solution s;
    return 0;
}

