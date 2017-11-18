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

void print(ListNode* head) {
  if (head) {
    cout << head->val << " ";
    print(head->next);
  }
}

ListNode* append(ListNode* head, int val) {
  if (!head) head = new ListNode(val);
  else head->next = append(head->next, val);
  return head;
}


class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int len = 0;
    for (ListNode* p = root; p; p = p->next) ++len;
    int c = len/k, m = len%k;
    vector<ListNode*> res(k);
    ListNode dummy(0); dummy.next = root;
    ListNode *head = &dummy;
    for (int i = 0; i < k; ++i) {
      ListNode* t = head;
      for (int j = 0; j < c; ++j) head = head->next;
      if (m) { head = head->next; --m; }
      res[i] = t->next;
      t->next = nullptr;
    }
    return res;
  }
};


int main() {
  Solution s;
  ListNode* root = new ListNode(1);
  root = append(root, 2);
  root = append(root, 3);
  root = append(root, 4);
  root = append(root, 5);
  root = append(root, 6);
  auto r = s.splitListToParts(root, 7);
  for (ListNode* e : r) {
    while (e) { cout << e->val << " "; e = e->next; }
    cout << endl;
  }
  return 0;
}
