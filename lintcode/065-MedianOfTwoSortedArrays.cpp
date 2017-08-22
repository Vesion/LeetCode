#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    int findk(int* A, int la, int* B, int lb, int k) {
        if (la > lb) return findk(B, lb, A, la, k);
        if (la == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int ka = min(la, k/2);
        int kb = k - ka;
        if (A[ka-1] < B[kb-1])
            return findk(A+ka, la-ka, B, lb, k-ka);
        else if (A[ka-1] > B[kb-1])
            return findk(A, la, B+kb, lb-kb, k-kb);
        else
            return A[ka-1];
    }

    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int la = A.size(), lb = B.size();
        if ((la+lb)%2) return findk(&A[0], la, &B[0], lb, (la+lb)/2+1);
        else return (findk(&A[0], la, &B[0], lb, (la+lb)/2) + findk(&A[0], la, &B[0], lb, (la+lb)/2+1)) * 0.5;
    }
};

int main() {
    Solution s;
    return 0;
}
