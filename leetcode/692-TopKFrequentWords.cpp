#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for (const string& w : words) ++m[w];
        using It = unordered_map<string,int>::const_iterator;
        struct Cmp {
            bool operator()(const It& it1, const It& it2) {
                if (it1->second == it2->second) return it1->first < it2->first;
                return it1->second > it2->second;
            }
        };
        priority_queue<It, vector<It>, Cmp> pq;
        for (It it = m.begin(); it != m.end(); ++it) {
            pq.push(it);
            if (!pq.empty() && pq.size() > k) pq.pop();
        }
        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top()->first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {
    return 0;
}
