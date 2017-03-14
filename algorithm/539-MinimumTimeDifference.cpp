#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> t(n);
        for (int i = 0; i < n; ++i) {
            int it = timePoints[i].find(":");
            int h = stoi(timePoints[i].substr(0, it));
            int m = stoi(timePoints[i].substr(it+1));
            t[i] = h*60+m;
        }
        sort(t.begin(), t.end()); // here we can also use counting sort in O(n), because the upper is 24*60
        t.push_back(t[0]+24*60);
        int res = INT_MAX;
        for (int i = 1; i <= n; ++i) res = min(res, t[i]-t[i-1]);
        return res;
    }
};


int main() {
    return 0;
}
