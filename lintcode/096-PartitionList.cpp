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
    ListNode *partition(ListNode *head, int x) {
        if (!head || !head->next) return head;
        ListNode small(0), large(0);
        ListNode *ps = &small, *pl = &large;
        while (head) {
            if (head->val < x) {
                ps->next = head;
                ps = ps->next;
            } else {
                pl->next = head;
                pl = pl->next;
            }
            head = head->next;
        }
        ps->next = large.next;
        pl->next = NULL;
        return small.next;
    }

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* appendNode(ListNode* head, int x) {
        if (!head) head = new ListNode(x);
        else head->next = appendNode(head->next, x);
        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    head = s.appendNode(head, 1);
    head = s.appendNode(head, 4);
    head = s.appendNode(head, 3);
    head = s.appendNode(head, 2);
    head = s.appendNode(head, 5);
    head = s.appendNode(head, 2);
    s.printList(head);

    head = s.partition(head, 3);
    s.printList(head);

    return 0;
}
