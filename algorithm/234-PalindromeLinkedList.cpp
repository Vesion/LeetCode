#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* appendNode(ListNode* head, int x) {
    if (!head)
        head = new ListNode(x);
    else
        head->next = appendNode(head->next, x);
    return head;
}

void printList(ListNode* head) {
    if (head) {
        cout << head->val << " ";
        printList(head->next);
    } else
        cout << "NULL" << endl;
}

void deleteList(ListNode* &head) {
    if (!head) return;
    deleteList(head->next);
    delete head;
    head = NULL;
}

// Solution 1 : use a array, O(n) time, O(n) space
bool isPalindrome_On(ListNode* head) {
    if (!head) return true;
    vector<int> vals;
    for (ListNode* p = head; p; p = p->next) vals.push_back(p->val);
    int left = 0, right = vals.size()-1;
    while (left <= right && vals[left] == vals[right]) ++left, --right;
    return left >= right;
}

// Solution 2 : reverse the first half of list while finding the middle, then compare it with the second half
bool isPalindrome(ListNode* head) {
    if (!head) return true;
    ListNode *slow = head, *fast = head;
    ListNode* prev = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    if (fast) slow = slow->next; // odd number of nodes, put slow to middle's next
    while (prev && slow && prev->val == slow->val) {
        prev = prev->next;
        slow = slow->next; 
    }
    return !prev;
}

int main() {
    ListNode* head = NULL;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 2);
    head = appendNode(head, 1);
    printList(head);

    cout << isPalindrome(head) << endl;

    deleteList(head);
    printList(head);
    return 0;
}
