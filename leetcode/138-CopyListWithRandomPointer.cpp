#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


// Solution 1 : hash map + dfs, Similar to 133-CloneGraph, O(n) space
class Solution1 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> copied;
        return dfs(head, copied);
    }

    RandomListNode* dfs(RandomListNode* head, unordered_map<RandomListNode*, RandomListNode*>& copied) {
        if (!head) return head;
        if (copied.count(head)) return copied[head];
        RandomListNode* newhead = new RandomListNode(head->label);
        copied[head] = newhead; // set copied before go forward
        newhead->next = dfs(head->next, copied);
        newhead->random = dfs(head->random, copied);
        return newhead;
    }
};


// Solution 2 : no-map, O(1) space
// insert copied node i between original node i and i+1, then set random pointers, lastly break them up
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
        }
        for (Node* cur = head; cur; cur = cur->next->next) {
            if (cur->random) cur->next->random = cur->random->next;
        }
        Node dummy(0);
        Node* copy = &dummy;
        for (Node* cur = head; cur; ) {
            copy->next = cur->next;
            copy = copy->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};


int main() {
    return 0;
}

