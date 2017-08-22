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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode* p = head;
        ListNode *prev = head, *cur = head->next;

        while (cur) {
            if (cur->val != prev->val) {
                p->next = cur;
                p = p->next;
            }
            prev = cur;
            cur = cur->next;
        }
        p->next = NULL;
        return head;
    }

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* appendList(ListNode* head, int val) {
        if (!head) head = new ListNode(val);
        else head->next = appendList(head->next, val);
        return head;
    }
};

int main() {
    Solution s;
    ListNode * head = NULL;
    head = s.appendList(head, 1);
    head = s.appendList(head, 2);
    head = s.appendList(head, 2);
    head = s.appendList(head, 3);
    head = s.appendList(head, 3);
    head = s.appendList(head, 3);
    s.printList(head);

    head = s.deleteDuplicates(head);
    s.printList(head);
    return 0;
}
