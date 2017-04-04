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
        vector<int> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i-1]+nums[i-1];

        for (int j = 0; j < n; ++j) {
            unordered_set<int> m;
            for (int i = 1; i < j-1; ++i) {
                int s1 = sums[i], s2 = sums[j]-sums[i+1];
                if (s1 == s2) m.insert(s1);
            }
            for (int k = j+2; k < n-1; ++k) {
                int s1 = sums[k]-sums[j+1], s2 = sums[n]-sums[k+1];
                if (s1 == s2 && m.count(s1)) return true;
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
