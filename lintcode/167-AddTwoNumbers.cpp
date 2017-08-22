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
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode* l3 = &dummy;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            l3->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next, l2 = l2->next, l3 = l3->next;
        }
        while (l1) {
            int sum = l1->val + carry;
            l3->next = new ListNode(sum%10);
            carry = sum/10;
            l1 = l1->next, l3 = l3->next;
        }
        while (l2) {
            int sum = l2->val + carry;
            l3->next = new ListNode(sum%10);
            carry = sum/10;
            l2 = l2->next, l3 = l3->next;
        }
        if (carry) {
            l3->next = new ListNode(carry);
        }
        return dummy.next;
    }    
};

int main() {
    Solution s;
    ListNode* l1 = NULL;
    l1 = append(l1, 1);
    l1 = append(l1, 1);
    l1 = append(l1, 1);
    print(l1);
    cout << endl;
    ListNode* l2 = NULL;
    l2 = append(l2, 9);
    l2 = append(l2, 9);
    l2 = append(l2, 9);
    print(l2);
    cout << endl;

    ListNode* l3 = s.addLists(l1, l2);
    print(l3);
    cout << endl;
    return 0;
}
