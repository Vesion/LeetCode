#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        if (length == 0) return {};
        vector<int> res(length, 0);
        for (auto& u : updates) {
            int start = u[0], end = u[1];
            int val = u[2];

            res[start] += val; // range start
            if (end+1 < length) res[end+1] -= val; // range end
        }

        int sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += res[i];
            res[i] = sum;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> u = {
        {1,3,2},
        {2,4,3},
        {0,2,-2},
    };
    auto r = s.getModifiedArray(5, u);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
