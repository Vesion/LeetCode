#include <iostream>
#include <vector>
using namespace std;

// similar to 264-UglyNumberII, maintain a sorted sequence of primes' multiples, O(n*k) time
int nthSuperUglyNumber(int n, vector<int>& primes) {
    sort(primes.begin(), primes.end());
    vector<int> ugly(n, INT_MAX);
    ugly[0] = 1;
    int k = primes.size();
    vector<int> index(k, 0); // indices to track each multiple
    vector<int> mp(k, 0); // prime multiple ugly
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            mp[j] = ugly[index[j]] * primes[j];
            ugly[i] = min(ugly[i], mp[j]);
        }
        for (int j = 0; j < k; ++j) if (ugly[i] == mp[j]) ++index[j];
    }
    return ugly[n-1];
}

int main() {
    vector<int> primes = {2, 7, 13, 19};
    for (int i = 1; i <= 12; ++i)
        cout << nthSuperUglyNumber(i, primes) << endl;
    return 0;
}
