#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Straight forward, O(n)
class RLEIterator0 {
public:
    vector<int> a;
    int i = 0;

    RLEIterator(vector<int>& A) {
        a = A;
    }

    int next(int n) {
        while (i < a.size()) {
            if (n - a[i] > 0) {
                n -= a[i];
                i += 2;
            }
            else {
                a[i] -= n;
                return a[i+1];
            }
        }
        return -1;
    }
};

// binary search, O(logn)
class RLEIterator {
public:
    using ll = long long;
    vector<ll> c;  // prefix sum of counts, A[0], A[0]+A[2], A[0]+A[2]+A[4]...
    vector<ll> a;  // numbers, A[1], A[3], A[5]...
    ll sumn = 0;
    int lower = 0;

    RLEIterator(vector<int>& A) {
        const int n = A.size();
        c.resize(n/2, 0);
        a.resize(n/2, 0);
        for (int i = 0; i < n/2; ++i) {
            c[i] = A[i*2]; if (i > 0) c[i] += c[i-1];
            a[i] = A[i*2+1];
        }
    }

    int next(int n) {
        sumn += n;
        int l = lower, r = c.size();
        while (l < r) {
            const int mid = l + (r - l)/2;
            if (c[mid] < sumn) l = mid + 1;
            else r = mid;
        }
        if (l == c.size()) return -1;
        lower = l;
        return a[l];
    }
};


int main() {
    return 0;
}
