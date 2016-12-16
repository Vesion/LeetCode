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

class Solution {
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        if (!head) return -1;
        int res = head->val;
        int c = 1;
        for (ListNode* p = head->next; p; p = p->next) {
            if (rand()%++c == 0) res = p->val;
        }
        return res;
    }
};

int main() {
    return 0;
}
