#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int maxh = 0;
        for (int i = heights.size()-1; i >= 0; --i) {
            if (heights[i] > maxh) res.push_back(i);
            maxh = max(maxh, heights[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

}