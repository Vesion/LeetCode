#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(0);
        ListNode* h = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                h->next = l1;
                l1 = l1->next;
            } else {
                h->next = l2;
                l2 = l2->next;
            }
            h = h->next;
        }
        if (l1) h->next = l1;
        if (l2) h->next = l2;
        return dummy.next;
    }   

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* appendNode(ListNode* head, int val) {
        if (!head) head = new ListNode(val);
        else head->next = appendNode(head->next, val);
        return head;
    }
};

int main() {
    Solution s;
    ListNode *h1 = NULL, *h2 = NULL;
    h1 = s.appendNode(h1, 1);
    h1 = s.appendNode(h1, 3);
    h1 = s.appendNode(h1, 5);
    h1 = s.appendNode(h1, 7);
    s.printList(h1);
    h2 = s.appendNode(h2, 2);
    h2 = s.appendNode(h2, 4);
    h2 = s.appendNode(h2, 6);
    h2 = s.appendNode(h2, 8);
    s.printList(h2);

    ListNode* h = s.mergeTwoLists(h1, h2);
    s.printList(h);

    return 0;
}
