#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

void printList(ListNode* &head) {
    if (head) {
        for (ListNode* p = head; p; p = p->next)
            cout << p->val << " ";
    }
    cout << "NULL" << endl;
    return;
}

ListNode* appendNode(ListNode* head, int x) {
    if (!head) {
        head = new ListNode(x);
    } else {
        ListNode *p = head;
        while (p->next) p = p->next;
        p->next = new ListNode(x);
    }
    return head;
}

void deleteList(ListNode* &head) {
    if (!head) return;
    while (head) {
        ListNode *p = head->next;
        delete head;
        head = p;
    }
    return;
}

// Solution 1 : O(n), in-place, care only about those nodes behind nodes larger or equal than x
// e.g.     1->2->4->3->2->1->5
//          x  x  x  x  ^  ^  x
ListNode* partition(ListNode* head, int x) {
    if (!head) return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *prev = &dummy, *cur = head;
    ListNode *insert = prev;
    int xp = INT_MAX, p = 0;
    while (cur) {
        ++p;
        if (cur->val >= x) xp = p;
        if (cur->val >= x || p <= xp) {
            if (cur->val < x)
                insert = insert->next;
            prev = cur;
            cur = cur->next;
        } else if (cur->val < x) {
            ListNode *cn = cur->next;
            prev->next = cur->next;
            ListNode *in = insert->next;
            insert->next = cur;
            cur->next = in;
            cur = cn;
            insert = insert->next;
        }
    }
    return dummy.next;
}

// Solution 2 : refer to others, O(n), two pointers
// 其实就是简单分治，而不是in-place处理，分别组成小于x的串，和大于等于x的串，再把两个串连起来，较方法1并没有加快
ListNode* partition_two(ListNode* head, int x) {
    ListNode left_dummy(-1), right_dummpy(-1);
    ListNode* left_cur = &left_dummy, *right_cur = &right_dummpy;
    for (ListNode *cur = head; cur; cur = cur->next) {
        if (cur->val < x) {
            left_cur->next = cur;
            left_cur = cur;
        } else {
            right_cur->next = cur;
            right_cur = cur;
        }
    }
    left_cur->next = right_dummpy.next;
    right_cur->next = NULL;
    return left_dummy.next;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 3);
    head = appendNode(head, 1);
    printList(head);

    //head = partition(head, 2);
    head = partition_two(head, 2);
    printList(head);

    deleteList(head);
    printList(head);
    return 0;
}
