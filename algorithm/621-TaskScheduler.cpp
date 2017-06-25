#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : greedy, construct the frame with tasks one by one
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        vector<int> m(26, 0);
        for (char& t : tasks) m[t-'A']++;
        int res = 0;
        priority_queue<int> q;
        for (int& c : m) if (c) q.push(c);
        while (!q.empty()) {
            vector<int> cache;
            int r = 0;
            for (int i = 1; i <= n+1; ++i) {
                if (q.empty()) continue;
                ++r;
                int t = q.top(); q.pop();
                if (t > 1) cache.push_back(t-1);
            }
            for (int& c : cache) q.push(c);
            res += cache.empty() ? r : n+1;
        }
        return res;
    }
};


// Solution 2 : math, calculate the size of frame directly, O(n)
class Solution_2 {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> m(26, 0);
        for (char& t : tasks) m[t-'A']++;
        sort(m.begin(), m.end());
        int i = 25;
        while (i >= 0 && m[i] == m[25]) --i;
        return max((int)tasks.size(), (m[25]-1)*(n+1) + (25-i));
    }
};


int main() {
    return 0;
}
