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

// Solution 1 : iterative
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *r = head, *p = head->next;
        while (p) {
            if (p->val != r->val) {
                r->next = p;
                r = r->next;
            }
            p = p->next;
        }
        r->next = NULL; // should free memory to delete nodes here
        return head;
    }
};


// Solution 2 :recursive
class Solution_2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};


int main() {
    Solution s;
    return 0;
}

