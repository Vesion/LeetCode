#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int INTMAX = 0x7fffffff;
const int INTMIN = 0x80000001;

int solve(vector<int>& nums) {
    int n = nums.size();
    int left = 0, minv = INTMAX;
    for (int i = n-1; i >= 0; --i) {
        if (nums[i] > minv) left = i;
        minv = min(minv, nums[i]);
    }
    int right = 0, maxv = INTMIN;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < maxv) right = i;
        maxv = max(maxv, nums[i]);
    }
    return right-left+1;
}


int main() {
    int N; cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    cout << solve(nums) << endl;
    return 0;
}
