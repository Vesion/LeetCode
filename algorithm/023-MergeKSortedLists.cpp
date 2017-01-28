#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};


// Solution 1 : heap, O(nlogk), TLE
class Solution_1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        auto cmp = [](const ListNode* h1, const ListNode* h2) {
            return h1->val > h2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* h : lists) if (h) pq.push(h);
        ListNode dummy(0);
        ListNode* head = &dummy;
        while (!pq.empty()) {
            ListNode* t = pq.top(); pq.pop();
            head->next = t;
            head = head->next;
            if (t->next) pq.push(t->next);
        }
        return dummy.next;
    }
};


// Solution 2 : divide and conquer, O(n)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        ListNode* head = NULL;
        for (ListNode* h : lists) {
            head = mergeTwoLists(head, h);
        }
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(0);
        ListNode* head = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1) head->next = l1;
        if (l2) head->next = l2;
        return dummy.next;
    }
};


int main() {
    return 0;
}
