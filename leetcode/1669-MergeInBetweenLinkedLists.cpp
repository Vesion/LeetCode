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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy(0); dummy.next = list1;
        ListNode* na = &dummy;
        for (int i = 0; i < a; ++i) na = na->next;
        ListNode* nb = na;
        for (int i = 0; i < b-a+1; ++i) nb = nb->next;
        na->next = list2;
        while (na->next) na = na->next;
        na->next = nb->next;
        return dummy.next;
    }
};


int main() {
}
