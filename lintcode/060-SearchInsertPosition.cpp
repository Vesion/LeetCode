#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // reimplement std::lower_bound
    int searchInsert(vector<int> &A, int target) {
        int left = 0, right = A.size();
        while (left < right) {
            int mid = left + (right-left)/2;
            if (A[mid] < target) left = mid+1;
            else right = mid;
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 3, 5, 6};
    cout << s.searchInsert(A, 0) << endl;
    return 0;
}
