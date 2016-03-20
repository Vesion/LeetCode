#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// learn to use std::partial_sum
class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) : sum(nums.size()+1, 0) {
        partial_sum(nums.begin(), nums.end(), sum.begin()+1);
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};



int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}
