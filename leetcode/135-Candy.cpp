#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <queue> 
using namespace std;

// Solution 1 : heap, O(nlogn) time
class Solution_heap {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> candy(n, 1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0 ; i< n; ++i) pq.push({rating[i], i});
        int res = 0;
        while (!pq.empty()) {
            int r = pq.top().first, i = pq.top().second; pq.pop();
            candy[i] = 1;
            if (i > 0 && r > rating[i-1]) candy[i] = candy[i-1]+1;
            if (i < n-1 && r > rating[i+1]) candy[i] = max(candy[i], candy[i+1]+1);
            res += candy[i];
        } 
        return res;
    }
};


// Solution 2 : two passed, O(n) time
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) // meet the rating from left to right
            if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        for (int i = n-2; i >= 0; --i) // meet the rating with both direction
            if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
        return accumulate(candies.begin(), candies.end(), 0);
    }
};


int main() {
    return 0;
}
