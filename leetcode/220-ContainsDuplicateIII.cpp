#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <unordered_map> 
using namespace std;

// Solution 1 : set, O(nlogn)
class Solution_1 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n == 0 || k == 0) return false;
        if (k >= n) k = n-1;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            if (i > k) s.erase(nums[i-k-1]); // ensure s contains at most k numbers

            auto it = s.lower_bound(nums[i]-t); // n2-n1 <= t
            if (it != s.end() && nums[i]-*it >= -t) // n2-n1 >= -t
                return true; // |n2-n1| <= t

            s.insert(nums[i]);
        }
        return false;
    }
};


// Solution 2 : bucket sort, O(n)
// https://discuss.leetcode.com/topic/27608/java-python-one-pass-solution-o-n-time-o-n-space-using-buckets/2
class Solution {
public:
    using ll = long long;

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n == 0 || k == 0 || t < 0) return false;
        ll w = (ll)t + 1;
        unordered_map<ll, ll> m;
        for (int i = 0; i < n; ++i) {
            ll id = getID(nums[i], w);
            if (m.count(id)) return true;
            if (m.count(id-1) && abs(nums[i]-m[id-1]) < w) return true;
            if (m.count(id+1) && abs(nums[i]-m[id+1]) < w) return true;
            m.insert({id, (ll)nums[i]});
            if (i >= k) m.erase(getID(nums[i-k], w));
        }
        return false;
    }

    ll getID(ll num, ll w) {
        return num < 0 ? (num + 1) / w - 1 : num / w;
    }
};


int main() {
    return 0;
}

