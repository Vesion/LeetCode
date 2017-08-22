#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// greedy, heap

// Solution 1 : one heap with cache
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        if (Profits.empty()) return 0;
        int n = Profits.size();
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; ++i) pq.push({Profits[i], Capital[i]});
        while (k-- && !pq.empty()) {
            vector<pair<int,int>> cache;
            while (!pq.empty() && W < pq.top().second) {
                cache.push_back(pq.top());
                pq.pop();
            }
            if (pq.empty()) break;
            W += pq.top().first;
            pq.pop();
            for (auto& p : cache) pq.push(p);
        }
        return W;
    }
};


// Solution 2 : two heaps
class Solution_2 {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        if (Profits.empty()) return 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> capPQ;
        priority_queue<pair<int,int>> proPQ;
        for (int i = 0; i < (int)Profits.size(); ++i) capPQ.push({Capital[i], Profits[i]});
        while (k--) {
            while (!capPQ.empty() && capPQ.top().first <= W) {
                proPQ.push({capPQ.top().second, capPQ.top().first});
                capPQ.pop();
            }
            if (proPQ.empty()) break;
            W += proPQ.top().first;
            proPQ.pop();
        }
        return W;
    }
};


int main() {
    Solution s;
    vector<int> p = {1, 2, 3};
    vector<int> c = {11, 12, 13};
    cout << s.findMaximizedCapital(11, 11, p, c) << endl;
    return 0;
}
