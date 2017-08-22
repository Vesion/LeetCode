#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <set> 
using namespace std;

// This is a NPC problem
//
// This solution has been proved wrong!
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto& t : transactions) {
            m[t[0]] += t[2];
            m[t[1]] -= t[2];
        }

        multiset<int> s;
        for (auto& p : m)
            if (p.second != 0) s.insert(p.second);

        int res = 0;
        while (!s.empty()) {
            int lower = *s.begin();
            s.erase(s.begin());
            int upper = *s.rbegin();
            s.erase(--s.end());
            int sum = lower + upper;
            if (sum != 0) s.insert(sum);
            ++res;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> t = { { 0,1,1 }, { 2,3,2 }, { 4,5,3 }, { 6,7,4 }, { 8,9,5 }, { 10,11,6 }, { 12,13,7 }, { 14,15,2 }, { 14,16,2 }, { 14,17,2 }, { 14,18,2 } };
    cout << s.minTransfers(t) <<endl;
    return 0;
}

