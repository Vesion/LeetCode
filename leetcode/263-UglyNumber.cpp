#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        return (num != 0) && ((num == 1) || (num%2 == 0 && isUgly(num/2)) || (num%3 == 0 && isUgly(num/3)) || (num%5 == 0 && isUgly(num/5)));
    }
};

int main() {
    Solution s;
    return 0;
}
