#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// Solution 1 : set
class Solution_1 {
public:
    int nthUglyNumber(int n) {
        if (n <= 5) return n;
        set<long long> s({1,2,3,4,5});
        long long res = 0;
        while (n--) {
            res = *s.begin();
            s.erase(s.begin());
            s.insert(res*2);
            s.insert(res*3);
            s.insert(res*5);
        }
        return res;
    }
};


// Solution 2 : dp, tracking the smallest generated number based to 2, 3, 5
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int r2 = res[p2]*2, r3 = res[p3]*3, r5 = res[p5]*5;
            res[i] = min(r2, min(r3, r5));
            if (res[i] == r2) ++p2;
            if (res[i] == r3) ++p3;
            if (res[i] == r5) ++p5;
        }
        return res[n-1];
    }
};


int main() {
    Solution s;
    cout << s.nthUglyNumber(7) << endl;
    return 0;
}

