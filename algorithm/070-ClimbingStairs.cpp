#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// It's fibonacci
class Solution {
public:
    int climbStairs(int n) {
        int pre = 1, cur = 1;
        while (n--) {
            cur += pre;
            pre = cur - pre;
        }
        return pre;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(4);
    return 0;
}

