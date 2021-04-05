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

class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode dummy; dummy.next = head;
        unordered_map<int,int> m;
        for (ListNode* cur = head; cur; cur = cur->next)
            ++m[cur->val];
        for (ListNode* cur = &dummy; cur->next; ) {
            if (m[cur->next->val] > 1) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};

int main() {

}