#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Given an array of size n, randomly pick k elements from it, the probability of picking any one element is k/n
//      Follow up: if given a data stream rather than a fixed size array, how to pick?
//
// Reservoir Sampling
//
// Simple proof:
//      1. when reach n-th element, the probability of picking it is obviously k/n
//      2. then the probability of picking the (n-1)-th element is:
//              k/(n-1) * [ (n-k)/n + k/n * (k-1)/k ] = k/n
//              (the probability of picking it) * (the probability of not picking n-th element + the probability of picking n-th but not removing (n-1)-th element)
//      3. for (n-2)-th, (n-3)-th, ..., 2nd, 1st element, we can proof them with deducation

vector<int> randomPickKElements(vector<int>&nums, int k) {
    int n = nums.size();
    if (n <= k) return nums;

    vector<int> res(k);
    for (int i = 0; i < k; ++i) res[i] = nums[i];

    for (int i = k; i < n; ++i) {
        int j = rand() % (i+1);
        if (j < k) res[j] = nums[i];
    }
    return res;
}


int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto r = randomPickKElements(nums, 4);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
