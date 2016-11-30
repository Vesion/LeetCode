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


// Solution 1 : copy value one by one
class Solution_1 {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre;
        while (node && node->next) {
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        pre->next = NULL;
        delete node;
    }
};


// Solution 2 : copy next node's whole data into current one, then free next one's memory
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        *node = *(node->next);
        delete tmp;
    }
};


int main() {
    Solution s;
    return 0;
}
