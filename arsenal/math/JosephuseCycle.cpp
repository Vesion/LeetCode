#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// http://blog.163.com/soonhuisky@126/blog/static/157591739201321341221179/

// Solution 1 : use list to simulate the process, O(N*M) time, O(N) space


// Solution 2 : math, O(N) time, O(1) space
//      F[1] = 0
//      F[i] = (F[i-1]+M) % i
class Solution {
public:
    int LastRemaining(int n, int m) {
        if (m == 0) return -1;
        int res = 0;
        for (int i = 2; i <= n; ++i) res = (res+m) % i;
        return res+1; // note which number is the first one in problem, here start with 1
    }
};


int main() {
    return 0;
}
