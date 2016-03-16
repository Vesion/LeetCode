#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

// a very good Sliding Window problem
// here given a very good article introducing it
// http://algorithmsandme.in/2014/03/heaps-sliding-window-algorithm/


// Solution 1 : use std::priority_queue, O(nlgn) time
using Pair = pair<int, int>;

struct PairComp {
    bool operator() (const Pair& p1, const Pair& p2) { return p1.first < p2.first; }
};

vector<int> maxSlidingWindow_heap(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return {};
    priority_queue<Pair, vector<Pair>, PairComp> q;
    vector<int> result(n-k+1);
    for (int i = 0; i < k; ++i) q.push(Pair(nums[i], i));
    for (int i = k; i < n; ++i) {
        Pair p = q.top();
        result[i-k] = p.first;
        while (!q.empty() && p.second <= i-k) { // if the largest one is out of window, pop it
            q.pop();
            p = q.top();
        }
        q.push(Pair(nums[i], i));
    }
    result[n-k] = q.top().first;
    return result;
}


// Solution 2 : use std::deque, O(n) time
vector<int> maxSlidingWindow_deque(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return {};
    deque<int> q; // store indices
    vector<int> result(n-k+1);
    for (int i = 0; i < k; ++i) { // push first k nums
        while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back(); // ensure deque's front is the largest one
        q.push_back(i);
    }
    for (int i = k; i < n; ++i) {
        result[i-k] = nums[q.front()];
        while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back(); // ditto
        q.push_back(i);
        if (!q.empty() && q.front() <= i-k) q.pop_front(); // pop those nums fall out window
    }
    result[n-k] = nums[q.front()];
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    //auto r = maxSlidingWindow_heap(nums, 1);
    auto r = maxSlidingWindow_deque(nums, 1);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
