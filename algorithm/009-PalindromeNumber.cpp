#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int n = 0;
        for (int cx = x; cx; cx /= 10) ++n;
        int m = n/2;
        int half = 0;
        while (m--) {
            half = half*10 + x%10;
            x /= 10;
        }
        if (n&1) x /= 10;
        return half == x;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(101);
    return 0;
}

