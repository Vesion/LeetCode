#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// The problem is pick k number from an array with preserved order, how to create a maximum number with these k numbers as digits
//      e.g. [9, 1, 2, 5, 8, 3], k = 2
//              the maximum number we can create is 98
//
// The solution is to maintain a k-length maximum stack as greedy strategy.


vector<int> maxNumber(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result(k); // here we use a vector directly instead of a real stack
    int t = 0; // the index of stack's top
    for (int i = 0; i < n; ++i) {
        while (n-i+t > k && t > 0 && result[t-1] < nums[i]) --t;
        if (t < k) result[t++] = nums[i];
    }
    return result;
}

int main() {
    vector<int> nums = {9, 1, 2, 5, 8, 3};    
    auto r = maxNumber(nums, 2);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
