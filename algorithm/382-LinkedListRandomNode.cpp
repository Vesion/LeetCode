#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};


ListNode* append(ListNode* head, int x) {
    if (!head) return new ListNode(x);
    head->next = append(head->next, x);
    return head;
}

void print(ListNode* head) {
    if (head) {
        cout << head->val << " ";
        print(head->next);
    }
}


// When n is extremely large, we cannot read in all datas once, so here space is limited.
// Reservoir Sampling, O(n) time, O(1) space
//
class Solution {
private:
    ListNode* head;
    int result;
    
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* p = head;
        result = p->val;
        int i = 1;
        while (p) {
            if (rand()%i++ == 0) result = p->val;
            p = p->next;
        }
        return result;
    }
};

int main() {
    ListNode* head = NULL;
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);
    Solution s(head);
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    return 0;
}
