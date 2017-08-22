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
    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *prev = NULL, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }    

    void print(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* append(ListNode* head, int x) {
        if (!head) head = new ListNode(x);
        else head->next = append(head->next, x);
        return head;
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    head = s.append(head, 1);
    head = s.append(head, 2);
    head = s.append(head, 4);
    s.print(head);
    head = s.reverse(head);
    s.print(head);
    return 0;
}
