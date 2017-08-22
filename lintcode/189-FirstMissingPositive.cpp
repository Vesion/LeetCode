#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// counting sort, put each number in [1, n] into proper position
//      e.g.  3,  4, -2,  9,  1   original numbers
//            1,  9,  3,  4, -2   after sorting
//            1,  2,  3,  4,  5   we want
//                ^

class Solution {
public:
    int firstMissingPositive(vector<int> A) {
        int n = A.size();

        for (int i = 0; i < n; ++i) {
            while (A[i] != i+1) {
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i]-1]) break; // out of range or they are same number
                swap(A[i], A[A[i]-1]);
            }
        }

        for (int i = 0; i < n; ++i)
            if (A[i] != i+1) return i+1;
        return n+1;
    }
};

int main() {
    Solution s; 
    vector<int> nums = { -1,4,2,1,9,10 };
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}
