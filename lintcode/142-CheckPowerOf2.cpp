#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPowerOf2(int n) {
        return (n > 0) && !(n&(n-1));
    }
};

int main() {
    Solution s;
    cout << s.checkPowerOf2(8) << endl;
    return 0;
}
