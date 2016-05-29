#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> 
using namespace std;

// Solution 1 : use std::make_heap and std::pop_heap
vector<int> topKFrequent_heap(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    unordered_map<int, int> m;
    for (auto &n : nums) m[n]++;

    vector<pair<int, int>> heap;
    for (auto &i : m) heap.push_back({i.second, i.first});

    vector<int> result; 
    make_heap(heap.begin(), heap.end());
    while (k--) {
        result.push_back(heap.front().second);
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
    }
    return result;
}


// Solution 1.2 : use std::priority_queue directly
vector<int> topKFrequent_pq(vector<int>& nums, int k) {
    if (nums.empty()) return {};
    unordered_map<int, int> m;
    for (auto &n : nums) m[n]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &i : m) {
        pq.push({i.second, i.first});
        if ((int)pq.size() > k) pq.pop();
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second); pq.pop();
    }
    return result;
}


int main() {
    vector<int> nums = { 4,1,-1,2,-1,2,3 };
    auto r = topKFrequent_heap(nums, 2);
    //auto r = topKFrequent_pq(nums, 2);
    for (auto &i : r) cout << i << " "; cout << endl;
    return 0;
}
