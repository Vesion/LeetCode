#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a^b, (a&b)<<1);    
    }
};

int main() {
    Solution s;
    cout << s.getSum(99, 99) <<endl;
    return 0;
}
