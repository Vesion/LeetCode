#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Solution 0 : brute-force, O(n^3), TLE
class Solution_0 {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;
        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1]+nums[i-1];

        for (int i = 0; i < n; ++i) {
            for (int j = i+2; j < n; ++j) {
                for (int k = j+2; k < n; ++k) {
                    int s1 = sums[i];
                    int s2 = sums[j]-sums[i+1];
                    int s3 = sums[k]-sums[j+1];
                    int s4 = sums[n]-sums[k+1];
                    if (s1 == s2 && s2 == s3 && s3 == s4) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


// Solution 1 : hash table, O(n^2)
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;
        vector<int> sums(n);
        partial_sum(nums.begin(), nums.end(), sums.begin());

        for (int k = 3; k < n-3; ++k) {
            unordered_set<int> pre;
            for (int i = 1; i < k-1; ++i) {
                if (sums[i-1] == sums[k-1]-sums[i]) pre.insert(sums[i-1]);
            }
            for (int j = k+1; j < n-1; ++j) {
                if (sums[n-1]-sums[j] == sums[j-1]-sums[k] &&
                    pre.count(sums[n-1]-sums[j])) return true;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums ={ 1,2,1,2,1,2,1 };
    cout << s.splitArray(nums) << endl;
    return 0;
}
