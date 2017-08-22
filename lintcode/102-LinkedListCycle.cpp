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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode dummy(0); dummy.next = head;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            if (fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }    
};

int main() {
    Solution s;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(1);
    ListNode* n4 = new ListNode(1);

    n1->next = n2;
    //n2->next = n2;
    //n3->next = n4;
    //n4->next = n1;

    cout << s.hasCycle(n1) << endl;;

    return 0;
}
