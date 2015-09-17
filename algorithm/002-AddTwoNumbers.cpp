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
    ListNode* head = NULL;
    ListNode** phead = &head;
    while (l1 != NULL || l2 != NULL) {
        x = getValueAndMoveNext(l1);
        y = getValueAndMoveNext(l2);
        sum = carry + x + y;
        *phead = new ListNode(sum%10);
        phead = &((*phead)->next);
        carry = sum / 10;
    }
    if (carry > 0) {
        *phead = new ListNode(carry%10);
    }
    return head;
}

ListNode* appendNode(ListNode* &head, int val) {
    ListNode* p = head;
    if (p == NULL) {
        p = new ListNode(val);
        head = p;
    } else {
        for (; p->next != NULL; p = p->next);
        p->next = new ListNode(val);
    }
    return head;
}

void freeList(ListNode* head) {
    ListNode* prev = head;
    while (head != NULL) {
        cout<<head->val<<endl;
        head = prev->next;
        free(prev);
        prev = head;
    }
}

// practise using two-level pointer
void removeNode(ListNode* head, int x) {
    ListNode** p = &head;
    while (*p != NULL) {
        ListNode *curr = *p;
        if (curr->val == x) {
            *p = (curr)->next;
            free(curr);
        } else
            p = &(curr->next);
    }
}

int main() {
    ListNode* h = NULL;
    appendNode(h, 1);
    appendNode(h, 2);
    appendNode(h, 3);
    appendNode(h, 4);
    appendNode(h, 5);
    removeNode(h, 4);
    freeList(h);
    return 0;
}
