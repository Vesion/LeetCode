#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// Solution 1 : heap, O(nlogk)
class Solution_1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int num : nums) m[num]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for (auto& p : m) {
            q.push({p.second, p.first});
            if ((int)q.size() > k) q.pop();
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};


// Solution 2 : bucket sort, O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int& num : nums) m[num]++;
        int n = nums.size();
        vector<vector<int>> buckets(n+1);
        for (auto& p : m) buckets[p.second].push_back(p.first);
        vector<int> res;
        for (int i = n; i >= 0; --i) {
            if (!buckets[i].empty()) res.insert(res.end(), buckets[i].begin(), buckets[i].end());
            if ((int)res.size() >= k) break;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    auto r = s.topKFrequent(nums, 2);
    for (auto& e : r) cout << e << " "; cout << endl;
    return 0;
}
