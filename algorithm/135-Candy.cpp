#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

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
    Solution s;
    return 0;
}

