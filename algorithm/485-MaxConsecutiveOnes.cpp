#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, len = 0;
        for (int& num : nums) {
            if (num == 1) ++len;
            else len = 0;
            res = max(res, len);
        }
        return res;
    }
};


int main() {
    return 0;
}
