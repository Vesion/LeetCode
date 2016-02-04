#include <iostream>
using namespace std;

// classical problem, F[n] = F[n-1] + F[n-2]

// solution 1 : recursion, top-down, TLE!
int climbStairs_topdown(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return climbStairs_topdown(n-1) + climbStairs_topdown(n-2);
}

// solution 2 : dp, bottom-up
int climbStairs_bottomup(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int n1 = 2, n2 = 1;
    int result;
    while (n-- > 2) {
        result = n1 + n2;
        n2 = n1;
        n1 = result;
    }
    return result;
}

// solution 3 : based on solution2, use matrix binary multiply to optimize
//

int main() {
    cout << climbStairs_topdown(4) << endl;
    cout << climbStairs_bottomup(4) << endl;
    return 0;
}
