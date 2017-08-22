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

void print(ListNode* head) {
    if (head) {
        cout << head->val << " ";
        print(head->next);
    }
}

ListNode* append(ListNode* head, int val) {
    if (!head) head = new ListNode(val);
    else head->next = append(head->next, val);
    return head;
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode dummy(0); dummy.next = head;
        ListNode *slow = &dummy, *fast = &dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return NULL;
        fast = &dummy;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }    
};

int main() {
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n5;

    ListNode* c = s.detectCycle(n1);
    if (c) cout << c->val << endl;
    else cout << "NULL" << endl;
    return 0;
}
