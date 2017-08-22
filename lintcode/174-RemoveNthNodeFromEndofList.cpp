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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || n <= 0) return head;
        ListNode dummy(0); dummy.next = head;
        ListNode *fast = head, *slow = &dummy;
        while (n-- && fast) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
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
    ListNode* head = NULL;
    head = s.appendNode(head, 1);
    head = s.appendNode(head, 2);
    head = s.appendNode(head, 3);
    head = s.appendNode(head, 4);
    head = s.appendNode(head, 5);
    s.printList(head);
    head = s.removeNthFromEnd(head, 5);
    s.printList(head);
    return 0;
}
