#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// similar to 767-ReorganizeString

// Solution 1 : greedy, construct the frame with tasks one by one
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m[26] = {};
        for (char c : tasks) ++m[c-'A'];
        priority_queue<int> pq;
        for (int t : m) if (t) pq.push(t);
        int res = 0;
        while (!pq.empty()) {
            vector<int> cache;
            int r = 0;
            for (int i = 0; i < n+1; ++i) {
                if (pq.empty()) break;
                int t = pq.top(); pq.pop();
                ++r;
                if (t > 1) cache.push_back(t-1);
            }
            if (cache.empty()) res += r;
            else res += n+1;
            for (int t : cache) pq.push(t);
        }
        return res;
    }
};


// Solution 2 : math, calculate the size of frame directly, O(n)
// https://leetcode.com/problems/task-scheduler/discuss/104504/C%2B%2B-8lines-O(n)
class Solution2 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m[26] = {};
        int maxc = 0;
        for (char c : tasks) {
            maxc = max(maxc, ++m[c-'A']);
        }
        int res = (maxc-1) * (n+1);
        for (int i = 0; i < 26; ++i) {
            if (m[i] == maxc) ++res;
        }
        // res is the most compact for most frequent arrangement, others can be inserted to any place,
        // so for those cases tasks.size() is the optimal result
        return max(int(tasks.size()), res);
    }
};


int main() {
    return 0;
}
