#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void deleteRandomList(RandomListNode* &head) {
    if (!head) return;
    deleteRandomList(head->next);
    delete head;
    head = NULL;
}

// Soltuion 1 : map, O(n) time, O(n) space 
// use hashmap to store original node and its copied node, for random pointer pointing
RandomListNode *copyRandomList_map(RandomListNode *head) {
    if (!head) return head;
    unordered_map<RandomListNode*, RandomListNode*> copied;
    RandomListNode* copyhead = new RandomListNode(head->label);
    copied[head] = copyhead;
    for (RandomListNode *p = head->next, *cp = copyhead; p; p=p->next) {
        cp->next = new RandomListNode(p->label); 
        cp = cp->next;
        copied[p] = cp;
    }
    for (RandomListNode *p = head; p; p=p->next) {
        copied[p]->random = copied[p->random];
    }
    return copyhead;
}


// Solution 2 : no-map, O(n) time, O(1) space
// insert copied node i between original node i and i+1, then set random pointers, lastly break them up
RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return head;

    // set next pointers
    for (RandomListNode* cur = head; cur; ) {
        RandomListNode* copied = new RandomListNode(cur->label);
        copied->next = cur->next;
        cur->next = copied;
        cur = copied->next;
    }

    // set random pointers
    for (RandomListNode* cur = head; cur; ) {
        if (cur->random) cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    // break up
    RandomListNode dummy(-1);
    for (RandomListNode *cur = head, *newcur = &dummy; cur; ) {
        newcur->next = cur->next;
        newcur = newcur->next;
        cur->next = cur->next->next;
        cur = cur->next;
    }
    return dummy.next;
}

int main() {
    return 0;
}
