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

ListNode* mergeTwoLists(ListNode *&p1, ListNode *&p2) {
    if (!p1) return p2;
    if (!p2) return p1;
    ListNode ph(-1);
    ListNode *p = &ph;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1) p->next = p1;
    if (p2) p->next = p2;
    return ph.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0)    
        return NULL;
    if (lists.size() == 1)
        return lists[0];
    ListNode* p1 = lists[0];
    for (int i = 1; i < lists.size() / 2; ++i)
        p1 = mergeTwoLists(p1, lists[i]);
    ListNode* p2 = lists[lists.size() / 2];
    for (int i = lists.size()/2+1; i < lists.size(); ++i)
        p2 = mergeTwoLists(p2, lists[i]);
    return mergeTwoLists(p1, p2);
}

int main() {
    ListNode *h1 = new ListNode(1);
    appendNode(h1, 3);
    appendNode(h1, 5);
    appendNode(h1, 7);
    printList(h1);

    ListNode *h2 = new ListNode(2);
    appendNode(h2, 4);
    appendNode(h2, 6);
    appendNode(h2, 8);
    printList(h2);

    ListNode *h3 = mergeTwoLists(h1, h2);
    printList(h3);
    system("pause");
    return 0;
}
