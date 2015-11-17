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
};

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

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1, *p2 = l2;
    ListNode *p
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);
    printList(head);
    head = deleteList(head);
    printList(head);
    system("pause");
    return 0;
}