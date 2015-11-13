#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

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

ListNode* removeNthNode(ListNode *head, int n) {
    ListNode **phead = &head;
    while (n--) {
        phead = &((*phead)->next);
    }
    ListNode *curr = *phead;
    *phead = curr->next;
    cout << curr->val << endl;
    free(curr);
    return head;
}

/* 
 * firstly, get the list length, so that get the (len-n)
 * then, use removeNthNode to remove the (len-n)th node
 * slowly!
 */
//ListNode* removeNthFromEnd(ListNode* head, int n) {
    //int len = 0;
    //ListNode *end = head;
    //while (end) {
        //++len;
        //end = end->next;
    //}
    //return removeNthNode(head, len-n);
//}

/* 
 * use two pointer a, b
 * a start go n steps first
 * a and b go together until a reach end
 * remove b
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode foo(0);
    ListNode *a = &foo, *b = &foo;
    a->next = b->next = head;
    for (int i = 0; i < n; ++i)
        a = a->next;
    while (a->next) {
        a = a->next;
        b = b->next;
    }
    ListNode *temp = b->next;
    b->next = temp->next;
    free(temp);
    return foo.next;
}

ListNode* freeList(ListNode* head) {
    while (head) {
        head = removeNthNode(head, 0);
    }
    return head;
}

int main() {
    ListNode *head = new ListNode(1);
    head = removeNthFromEnd(head, 1);
    freeList(head);

    return 0;
}
