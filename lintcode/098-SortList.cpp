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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1; 
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return dummy.next;
    }

    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(fast);
        return merge(left, right);
    }    
};

int main() {
    Solution s;
    ListNode* head = NULL;
    head = append(head, 3);
    head = append(head, 6);
    head = append(head, 2);
    head = append(head, 9);
    head = append(head, 8);
    head = append(head, 5);
    head = append(head, 1);
    print(head);
    cout << endl;

    head = s.sortList(head);
    print(head);
    return 0;
}
