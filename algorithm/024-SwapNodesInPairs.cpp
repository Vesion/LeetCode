#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

void printList(ListNode *head) {
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

ListNode* appendNode(ListNode *head, int x) {
    ListNode *p = head;
    while (p->next)
        p = p->next;
    ListNode *node = new ListNode(x);
    p->next = node;
    return head;
}

ListNode* deleteList(ListNode *head) {
    ListNode *p = head;
    while (p) {
        ListNode *node = p;
        p = node->next;
        delete node;
    }
    return p;
}

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next)
        return head;    
    ListNode** pn1 = &head;
    ListNode* newhead = head->next;
    while (*pn1 && (*pn1)->next) {
        ListNode* n2 = (*pn1)->next;

        (*pn1)->next = n2->next;
        n2->next = *pn1;
        *pn1 = n2;

        pn1 = &((*pn1)->next->next);
    }
    return newhead;
}

int main() {
    ListNode *h1 = new ListNode(1);
    appendNode(h1, 3);
    appendNode(h1, 5);
    appendNode(h1, 7);
    appendNode(h1, 9);
    printList(h1);

    h1 = swapPairs(h1);
    printList(h1);
    system("pause");
    return 0;
}
