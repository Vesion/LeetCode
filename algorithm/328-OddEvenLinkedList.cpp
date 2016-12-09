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
        ListNode *odd = head, *even = head->next;
        bool f = true;
        ListNode *po = odd, *pe = even;
        while (po->next && pe->next) {
            if (f) {
                po->next = pe->next;
                po = pe->next;
            } else {
                pe->next = po->next;
                pe = po->next;
            }
            f = !f;
        }
        pe->next = NULL;
        po->next = even;
        return odd;
    }
};

int main() {
    return 0;
}
