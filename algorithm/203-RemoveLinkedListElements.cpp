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


// Solution 1.1 : trivial
class Solution_1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode dummy(0); dummy.next = head;
        ListNode *pre = &dummy, *cur = head;
        while (cur) {
            if (cur->val == val) pre->next = cur->next;
            else pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};


// Solution 1.2 : recursive
class Solution_12 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};


// Solution 2 : two-level pointers
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode** phead = &head;
        while (*phead) {
            if ((*phead)->val == val) *phead = (*phead)->next;
            else phead = &(*phead)->next;
        }
        return head;
    }
};


int main() {
    Solution s;
    return 0;
}

