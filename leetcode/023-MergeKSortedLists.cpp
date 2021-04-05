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


// Solution 1 : heap, O(nlogk)
class Solution1 {
public:
    struct Lcmp {
        bool operator()(const ListNode* n1, const ListNode* n2) {
            return n1->val > n2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* cur = &dummy;
        priority_queue<ListNode*, vector<ListNode*>, Lcmp> pq;
        for (ListNode* node : lists) if (node) pq.push(node);
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) pq.push(node->next);
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
