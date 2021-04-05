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

//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode small_dummy(0);
        ListNode* small = &small_dummy;
        ListNode large_dummy(0);
        ListNode* large = &large_dummy;
        
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                small->next = cur;
                small = small->next;
            } else {
                large->next = cur;
                large = large->next;
            }
        }
        small->next = large_dummy.next;
        large->next = NULL;
        return small_dummy.next;
    }
};


int main() {
    return 0;
}

