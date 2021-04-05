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
    Node* insert(Node* head, int a) {
        if (!head) {
            Node* h = new Node(a);
            h->next = h;
            return h;
        }
        Node* cur = head;
        while (cur->next != head) {
            int cv = cur->val, nv = cur->next->val;
            if (cv <= a && a <= nv) break;  // in middle
            if (cv > nv && (cv <= a || a <= nv)) break;  // in the last position
            cur = cur->next;
        }
        Node* ni = new Node(a);
        ni->next = cur->next;
        cur->next = ni;
        return head;
    }
};

int main() {

}