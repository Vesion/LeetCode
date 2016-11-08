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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p1 = head;
        while(n--) p1 = p1->next;
        ListNode* p2 = &dummy;
        while (p1) {
            p2 = p2->next;
            p1 = p1->next;
        }
        p2->next = p2->next->next;
        return dummy.next;
    }
};

int main() {
    Solution s;
    return 0;
}

