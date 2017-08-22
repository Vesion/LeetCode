#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode* next;
    RandomListNode* random;
    RandomListNode(int label) : label(label), next(NULL), random(NULL) {}
};

void print(RandomListNode* head) {
    if (head) {
        cout << head->label << " ";
        print(head->next);
    }
}

RandomListNode* append(RandomListNode* head, int label) {
    if (!head) head = new RandomListNode(label);
    else {
        head->next = append(head->next, label);
        head->random = NULL;
    }
    return head;
}

// Solution 1 : map<original node, copied node>, O(n) space
class Solution_1 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        map<RandomListNode*, RandomListNode*> m;

        RandomListNode* chead = new RandomListNode(head->label);
        m[head] = chead;
        RandomListNode* cp = chead;

        for (RandomListNode* p = head->next; p; p = p->next) {
            cp->next = new RandomListNode(p->label);
            cp = cp->next;
            m[p] = cp;
        }
        for (RandomListNode* p = head; p; p = p->next) {
            m[p]->random = m[p->random];
        }

        return chead;
    }   
};


// Solution 2 : O(1) space
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        for (RandomListNode* p = head; p; ) { // generate copied nodes
            RandomListNode* c = new RandomListNode(p->label);
            c->next = p->next;
            p->next = c;
            p = c->next;
        }
        for (RandomListNode* p = head; p; p = p->next->next) { // set randoms
            if (p->random) p->next->random = p->random->next;
        }

        RandomListNode dummy(0);
        for (RandomListNode *p = head, *ch = &dummy; p; ) { // break up
            ch->next = p->next; 
            ch = ch->next;
            p->next = ch->next;
            p = ch->next;
        }
        return dummy.next;
    }
};

int main() {
    Solution s;
    RandomListNode* head = NULL;
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);
    print(head); cout << endl;

    RandomListNode* chead = s.copyRandomList(head);
    print(chead); cout << endl;
    return 0;
}
