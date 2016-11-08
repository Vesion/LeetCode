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
class Solution_2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode* new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }

    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode* pre = end;
        while (begin != end) {
            ListNode* tmp = begin->next;
            begin->next = pre;
            pre = begin;
            begin = tmp;
        }
        return pre;
    }
};

int main() {
    Solution s;
    return 0;
}

