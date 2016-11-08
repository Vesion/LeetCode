#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        for (; x; x /= 10) {
            if (res < INT_MIN/10 || res > INT_MAX/10) // Checking the over/underflow.
                return 0;
            res = res*10 + x%10;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverse(1000000);
    return 0;
}

