#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < n; ++i) pq.push({nums[i], i});
        vector<string> res(n);
        int rank = 1;
        while (!pq.empty()) {
            int i = pq.top().second; pq.pop();
            string s;
            if (rank == 1) s = "Gold Medal";
            else if (rank == 2) s = "Silver Medal";
            else if (rank == 3) s = "Bronze Medal";
            else s = to_string(rank);
            res[i] = s;
            ++rank;
        }
        return res;
    }
};


int main() {
    return 0;
}
