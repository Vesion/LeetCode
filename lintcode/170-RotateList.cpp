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
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;

        int l = 1;
        ListNode* p = head;
        while (p->next) {
            ++l;
            p = p->next;
        }
        k %= l;

        p->next = head; // form a cycle
        for (int i = 0; i < l-k; ++i) p = p->next;
        head = p->next;
        p->next = NULL;
        return head;
    }

    void print(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* append(ListNode* head, int val) {
        if (!head) head = new ListNode(val);
        else head->next = append(head->next, val);
        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    head = s.append(head, 1);
    head = s.append(head, 2);
    head = s.append(head, 3);
    head = s.append(head, 4);
    head = s.append(head, 5);
    s.print(head);

    head = s.rotateRight(head, 0);
    s.print(head);
    return 0;
}
