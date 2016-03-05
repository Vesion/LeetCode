#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 0 : use std::sort, O(nlgn) time
int maximumGap_stl(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int i = 0; i < n-1; ++i)
        result = max(result, abs(nums[i+1]-nums[i]));
    return result;
}


// Solution 1 : pigeon hole principle and bucket sort, O(n) time
// According to pigeon hole priciple, the lower bound of the gap is (max_num - min_num)/(n-1), the bucket size. So the max gap must appear in between ajacent bucket.
int maximumGap(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int max_num = nums[0], min_num = nums[0];
    if (n&1) nums.push_back(nums[n++-1]);
    for (int i = 0; i < n-1; i += 2) {
        if (nums[i] > nums[i+1]) {max_num = max(max_num, nums[i]); min_num = min(min_num, nums[i+1]);}
        else {max_num = max(max_num, nums[i+1]); min_num = min(min_num, nums[i]);}
    }
    if (max_num == min_num) return 0;

    int bucket_size = max(1, (max_num - min_num) / (n-1));
    int bucket_num = (max_num - min_num) / bucket_size + 1;
    if (bucket_num <= 1) return max_num - min_num;
    vector<int> bucket_max(bucket_num, 0); // store max num of each bucket
    vector<int> bucket_min(bucket_num, INT_MAX); // store min num of each bucket
    for (auto & num : nums) {
        int i = (num - min_num) / bucket_size;
        cout << i << endl;
        bucket_max[i] = max(bucket_max[i], num);
        bucket_min[i] = min(bucket_min[i], num);
    }

    int result = 0;
    int last_max = min_num;
    for (int i = 0; i < bucket_num; ++i) {
        if (bucket_max[i] != 0) {
            result = max(result, bucket_min[i] - last_max);
            last_max = bucket_max[i];
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 4, 5, 8, 9, 11};
    cout << maximumGap(nums) << endl;
    return 0;
}
