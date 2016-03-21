#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Solution 0 : a little bit better than brute-force, while sumRange is still O(n) :(
class NumArray_bf {
private:
    vector<int> sum;
    vector<int> upt;
    int left;
public:
    NumArray_bf(vector<int> &nums) : sum(nums.size()+1, 0), upt(nums.begin(), nums.end()) {
        left = INT_MAX;
        partial_sum(nums.begin(), nums.end(), sum.begin()+1);
    }

    void update(int i, int val) {
        left = min(left, i);
        upt[i] = val;
    }

    int sumRange(int i, int j) {
        if (j >= left) {
            for (int k = left+1; k <= j+1; ++k)
                sum[k] = sum[k-1] + upt[k-1];
            left = j;
        }
        return sum[j+1] - sum[i];
    }
};


// Solution 1 : segment tree. To be continued :)
class NumArray {
public:
    NumArray(vector<int> &nums) {
        
    }

    void update(int i, int val) {
        
    }

    int sumRange(int i, int j) {
        
    }
};


int main() {
    vector<int> nums = {1, 3, 5};
    NumArray_bf numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl;
    return 0;
}
