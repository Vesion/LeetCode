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
class Solution_1 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        ListNode dummy(0); dummy.next = head;
        ListNode *front = head, *behind = &dummy;
        while (front) {
            ListNode* next_behind = front;

            int ck = k-1;
            while (front && ck--) front = front->next;
            if (!front) break; // remains

            ListNode* next_front = front->next;

            // reverse
            ListNode* prev = behind->next;
            ListNode* cur = prev->next;
            ListNode *next;
            while (prev != front) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            behind->next = front;
            next_behind->next = next_front;

            behind = next_behind;
            front = next_front;
        }
        return dummy.next;
    }
};


// Solution 2 : recursive
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode *p = head;
        int ck = k;
        while (ck--) {
            if (!p) return head;
            p = p->next;
        }
        ListNode* newhead = reverse(head, k);
        head->next = reverseKGroup(p, k);
        return newhead;
    }

    ListNode* reverse(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* newhead = reverse(head->next, k-1);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};


int main() {
    return 0;
}

