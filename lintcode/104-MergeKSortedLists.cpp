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
        ListNode* l = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }
        if (l1) l->next = l1;
        if (l2) l->next = l2;
        return dummy.next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;
        int n = lists.size();
        if (n == 1) return lists[0];
        ListNode *head = lists[0];
        for (int i = 1; i < n; ++i)
            head = merge(head, lists[i]);
        return head;
    } 
};

int main() {
    Solution s;
    ListNode* l1 = NULL;
    l1 = append(l1, 1);
    ListNode* l2 = NULL;
    l2 = append(l2, 2);

    vector<ListNode*> v({l1, l2});

    ListNode* h = s.mergeKLists(v);
    return 0;
}
