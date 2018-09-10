#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Bucket Sort is a very useful solution for frequency-related problems
// and is related to Pigeonhole Principle

// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution_sort_characters {
public:
    string frequencySort(string s) {
        vector<int> m(128, 0);
        for (char& c : s) m[c]++;
        
        int n = s.size();
        vector<string> buckets(n+1);
        for (int c = 0; c < 128; ++c) buckets[m[c]] += string(m[c], (char)c);
        
        string res;
        for (int i = n; i >= 0; --i) res += buckets[i];
        return res;
    }
};


// https://leetcode.com/problems/top-k-frequent-elements/
class Solution_topk {
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
    return 0;
}
