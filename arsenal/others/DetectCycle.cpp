#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Many problems can be converted into 'Finding Cycle' problems, 
// most of time they can be solved with 'two pointers' solution used in linked list

// Find cycle in a linked list:
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

class Solution_list {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return head;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { // found cycle
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


// https://leetcode.com/problems/find-the-duplicate-number/
class Solution_duplicate {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


// https://leetcode.com/problems/happy-number/
class Solution_happynumber {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = next(slow);
            fast = next(next(fast));
            if (slow == fast) break;
        }
        return slow == 1;
    }
    
    int next(int n) {
        int sum = 0;
        while (n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
};


int main() {
    return 0;
}
