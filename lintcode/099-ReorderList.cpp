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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        int l = 0;
        for (ListNode* p = head; p; p = p->next) ++l;
        l = (l+1)/2-1;

        ListNode* right = head;
        while (l--) right = right->next;
        ListNode *prev = NULL, *cur = right->next;;
        right->next = NULL;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        right = prev;

        ListNode* left = head;
        while (left && right) {
            ListNode* lnext = left->next;
            ListNode* rnext = right->next;
            left->next = right;
            right->next = lnext; 
            left = lnext;
            right = rnext;
        }
    }    
};

int main() {
    Solution s;
    ListNode* head = NULL;
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);
    head = append(head, 6);
    print(head);
    cout << endl;

    s.reorderList(head);
    print(head);
    cout << endl;
    return 0;
}
