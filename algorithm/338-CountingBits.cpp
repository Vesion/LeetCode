#include <iostream>
#include <vector>
using namespace std;


// Solution 1 : brute-force, O(n*k) time, 124ms, k is the average number of 1s in all n integers
// for each i, call to a caculation like in 191-NumberOf1Bits, every num is independent
vector<int> countBits_bf(int num) {
    vector<int> result(num+1, 0);
    for (int i = 0; i <= num; ++i) {
        int j = i, k = i;
        while (j) {
            j &= (j-1);
            result[k]++;
        }
    }
    return result;
}


// Solution 2 : dp, 121ms
vector<int> countBits_dp(int num) {
    vector<int> result(num+1, 0);
    for (int i = 1; i <= num; ++i)
        result[i] = result[i&(i-1)] + 1; // drops the lowest set(1) bit
    return result;
}

// Solution 2 v2 : dp, 120ms
vector<int> countBits_dp_v2(int num) {
    vector<int> result(num+1, 0);
    for (int i = 1; i <= num; ++i)
        result[i] = result[i>>1] + (i&1); // drops the lowest(0 or 1) bit
    return result;
}

int main() {
    auto r = countBits_dp_v2(5);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
