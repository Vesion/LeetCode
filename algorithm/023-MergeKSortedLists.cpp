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


// Solution 2 : divide and conquer, like merge sort, O(nlogk)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int k = lists.size();
        while (k > 1) {
            for (int i = 0; i < k/2; ++i)
                lists[i] = mergeTwoLists(lists[i], lists[k-1-i]);
            k = (k+1)/2;
        }
        return lists.front();
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


int main() {
    return 0;
}
