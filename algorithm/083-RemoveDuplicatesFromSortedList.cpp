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
        ListNode *p1 = head, *p2 = head;
        while (p2) {
            if (p1->val != p2->val) {
                p1->next = p2;
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        p1->next = NULL;
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
    return 0;
}
