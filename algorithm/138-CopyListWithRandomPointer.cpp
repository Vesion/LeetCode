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
class Solution {
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
class Solution_2 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        for (RandomListNode* cur = head; cur; ) {
            RandomListNode* copied = new RandomListNode(cur->label);
            copied->next = cur->next;
            cur->next = copied;
            cur = copied->next;
        }
        
        for (RandomListNode* cur = head; cur; ) {
            RandomListNode* copied = cur->next;
            if (cur->random) // be careful with NULL random
                copied->random = cur->random->next;
            cur = cur->next->next;
        }
        
        RandomListNode dummy(0);
        RandomListNode* p = &dummy;
        for (RandomListNode* cur = head; cur; ) {
            p->next = cur->next;
            p = p->next;
            cur->next = p->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};



int main() {
    Solution s;
    return 0;
}

