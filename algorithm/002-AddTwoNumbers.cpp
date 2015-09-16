#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getValueAndMoveNext(ListNode* &l) {
    int val = 0;
    if (l != NULL) {
        val = l->val;
        l = l->next;
    }
    return val;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, x = 0, y = 0;
    int sum = 0;
    ListNode* header = NULL;
    ListNode** pheader = &header;
    while (l1 != NULL || l2 != NULL) {
        x = getValueAndMoveNext(l1);
        y = getValueAndMoveNext(l2);
        sum = carry + x + y;
        *pheader = new ListNode(sum%10);
        pheader = &((*pheader)->next);
        carry = sum / 10;
    }
    if (carry > 0) {
        *pheader = new ListNode(carry%10);
    }
    return header;
}

int main() {
    return 0;
}
