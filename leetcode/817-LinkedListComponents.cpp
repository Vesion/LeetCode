#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> m(G.begin(), G.end());
        bool f = false;
        int res = 0;
        while (head) {
            if (!m.count(head->val)) f = false;
            else {
                if (!f) ++res;
                f = true;
            }
            head = head->next;
        }
        return res;
    }
};

int main() {

}
