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
        int m = n/2; // reverse half, in case overflow
        int half = 0;
        while (m--) {
            half = half*10 + x%10;
            x /= 10;
        }
        if (n&1) x /= 10;
        return half == x;
    }
};

// to string
class Solution1 {
public:
    bool isPalindrome(int x) {
        const string s = to_string(x);
        const int n = s.size();
        for (int i = 0, j = n-1; i <= j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
