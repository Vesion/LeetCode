#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1;
        int k = m+n-1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) A[k--] = A[i--];
            else A[k--] = B[j--];
        }
        while (i >= 0) A[k--] = A[i--];
        while (j >= 0) A[k--] = B[j--];
    }
};

int main() {
    Solution s;
    int A[6] = {0, 1, 2, 3, 4, 7};
    int B[0] = {};
    s.mergeSortedArray(A, 0, B, 0);
    for (auto i : A) cout << i << " ";
    return 0;
}
