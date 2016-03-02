#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* appendNode(ListNode* head, int x) {
    if (!head) {
        head = new ListNode(x);
        return head;
    }
    head->next = appendNode(head->next, x);
    return head;
}

void printList(ListNode* head) {
    if (head) {
        for (ListNode* p = head; p; p=p->next)
            cout << p->val << " ";
    }
    cout << "NULL" << endl;
}

void deleteList(ListNode* &head) {
    if (!head) return;
    deleteList(head->next);
    delete head;
    head = NULL;
}

bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n1;
    //printList(head);

    cout << hasCycle(head) << endl;

    deleteList(head);
    printList(head);
    return 0;
}
