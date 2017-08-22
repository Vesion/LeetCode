#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode odd(0), even(0);
        odd.next = even.next = head;
        ListNode *po = &odd, *pe = &even;
        while (head) {
            po->next = head;
            po = po->next;
            pe->next = head->next;
            pe = pe->next;
            head = head->next ? head->next->next : head->next;
        }
        po->next = even.next;
        return odd.next;
    }
};


int main() {
    return 0;
}
