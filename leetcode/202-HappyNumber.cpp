#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Solution 1 : hash table, trivial
class Solution_1 {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while (true) {
            int sum = 0;
            while (n) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            if (sum == 1) return true;
            if (s.count(sum)) break;
            s.insert(sum);
            n = sum;
        }
        return false;
    }
};


// Solution 2 : two-pointers, similar to 141-LinkedListCycle
class Solution {
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
