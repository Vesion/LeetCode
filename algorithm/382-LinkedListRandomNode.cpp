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

// Reservoir Sampling algorithm
class Solution {
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int res = 0, c = 0;
        for (ListNode* p = head; p; p = p->next)
            if (rand()%(++c) == 0) res = p->val;
        return res;
    }
};

int main() {
    return 0;
}
