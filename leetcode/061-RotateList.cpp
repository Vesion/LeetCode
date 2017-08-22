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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode* p = head;
        for (; p->next; p = p->next) ++len;
        k %= len;
        if (k == 0) return head;

        p->next = head; // connect to a cycle
        for (int i = 0; i < len-k; ++i) p = p->next;
        head = p->next;
        p->next = NULL; // break the cycle
        return head;
    }
};


int main() {
    return 0;
}
