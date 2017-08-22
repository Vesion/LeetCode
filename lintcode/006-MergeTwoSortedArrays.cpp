#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        int na = A.size(), nb = B.size();
        vector<int> C(na+nb);
        int i = 0, j = 0, k = 0;
        while (i < na && j < nb) {
            if (A[i] < B[j]) C[k++] = A[i++];
            else C[k++] = B[j++];
        }
        while (i < na) C[k++] = A[i++];
        while (j < nb) C[k++] = B[j++];
        return C;
    } 
};

int main() {
    Solution s;
    vector<int> A = {1, 2, 3, 4}, B = {2, 4, 5, 6};
    auto C = s.mergeSortedArray(A, B);
    for (auto i : C) cout << i << " "; cout << endl;
    return 0;
}
