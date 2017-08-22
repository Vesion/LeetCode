#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int fastPower(int a, int b, int n) {
        long long r = 1;
        long long al = a;
        while (n) {
            if (n & 1) r = r * al % b;
            al = al * al % b;
            n >>= 1;
        }
        return r % b;
    }
};

int main() {
    Solution s;
    cout << s.fastPower(2, 2147483647, 2147483647) << endl;
    return 0;
}
