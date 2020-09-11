#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Brute-force, O(n*n)
class Solution0 {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int res = 0;
        int suml = 0, i = 0, j = 0;
        for (; j < A.size(); ++j) {
            suml += A[j];
            if (j-i+1 > L) suml -= A[i++];
            if (j-i+1 < L) continue;
            int summ = 0, p = 0, q = 0;
            for (; q < i; ++q) {
                summ += A[q];
                if (q-p+1 > M) summ -= A[p++];
                if (q-p+1 < M) continue;
                res = max(res, suml + summ);
            }
            summ = 0, p = j+1, q = j+1;
            for (; q < A.size(); ++q) {
                summ += A[q];
                if (q-p+1 > M) summ -= A[p++];
                if (q-p+1 < M) continue;
                res = max(res, suml + summ);
            }
        }
        return res;
    }
};

// Map, O(nlogn)
class Solution1 {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sumls, summs;
        int ls = 0, ms = 0;
        for (int li = 0, mi = 0, j = 0; j < A.size(); ++j) {
            ls += A[j];
            ms += A[j];
            if (j-li+1 > L) ls -= A[li++];
            if (j-mi+1 > M) ms -= A[mi++];
            if (j >= L-1) sumls.push_back(ls);
            if (j >= M-1) summs.push_back(ms);
        }
        int res = 0;
        map<int,int> m;
        for (int i = 0; i < sumls.size(); ++i) {
            if (i == 0) {
                for (int j = L; j < summs.size(); ++j) {
                    ++m[summs[j]];
                }
            } else {
                if (i+L-1 >= 0 && i+L-1 < summs.size()) {
                    if (--m[summs[i+L-1]] == 0) m.erase(summs[i+L-1]);
                }
                if (i-M >= 0 && i-M < summs.size()) {
                    ++m[summs[i-M]];
                }
            }
            res = max(res, sumls[i] + (m.empty() ? 0 : m.rbegin()->first));
        }
        return res;
    }
};

// DP, O(n)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> s(A.size(), 0);
        for (int i = 0; i < A.size(); ++i) {
            s[i] = i > 0 ? A[i] + s[i-1] : A[i];
        }

        int res = 0, max_summ = 0, max_suml = 0;
        for (int i = L+M-1; i < s.size(); ++i) {
            int suml = s[i] - s[i-L];
            int summ = s[i-L] - (i-L-M >= 0 ? s[i-L-M] : 0);
            max_summ = max(max_summ, summ);
            res = max(res, max_summ + suml);
        }
        for (int i = L+M-1; i < s.size(); ++i) {
            int summ = s[i] - s[i-M];
            int suml = s[i-M] - (i-L-M >= 0 ? s[i-L-M] : 0);
            max_suml = max(max_suml, suml);
            res = max(res, max_suml + summ);
        }
        return res;
    }
};


int main() {
}
