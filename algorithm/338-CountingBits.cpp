#include <iostream>
#include <vector>
using namespace std;

// Solution 2 : dp, O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        res[1] = 1;
        for (int i = 2; i <= num; ++i) res[i] = (i&1) + res[i>>1];
        return res;
    }
};


int main() {
    return 0;
}
