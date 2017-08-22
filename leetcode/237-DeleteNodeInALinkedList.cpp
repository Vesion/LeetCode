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
        ListNode* pre = NULL;
        while (node->next) {
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        if (pre) pre->next = NULL;
    }
};


// Solution 2 : copy next node's whole data into current one, then free next one's memory
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node) return;
        ListNode* tmp = node->next;
        *node = *(node->next);
        delete tmp;
    }
};


int main() {
    return 0;
}
