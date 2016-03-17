#include <iostream>
#include <vector>
#include <set>
using namespace std;

// dp problem, the key idea is to maintain a sorted array of 2, 3, 5's multiples


// Solution 1 : do not sort myself, but use std::set, slow
int nthUglyNumber_set(int n) {
    if (n <= 5) return n;
    set<long long> s;
    for (int i = 1; i <= 5; ++i) s.insert(i);
    long long result = 0;
    while (n--) {
        result = *s.begin();
        s.erase(s.begin());
        for (int i = 2; i <= 5; ++i) s.insert(i*result);
    }
    return result;
}


// Solution 2 : maintain myself, use three indices to trace the last generated numbers based to 2, 3, 5, fast
int nthUglyNumber(int n) {
    vector<int> ugly(n, 1);
    int p2 = 0, p3 = 0, p5 = 0; // indices
    for (int i = 1; i < n; ++i) {
        int m2 = ugly[p2]*2, m3 = ugly[p3]*3, m5 = ugly[p5]*5;
        ugly[i] = min(m2, min(m3, m5));
        if (ugly[i] == m2) ++p2;
        if (ugly[i] == m3) ++p3;
        if (ugly[i] == m5) ++p5;
    }
    return ugly[n-1];
}

int main() {
    cout << nthUglyNumber(1407) << endl;
    cout << nthUglyNumber_set(1407) << endl;
    return 0;
}
