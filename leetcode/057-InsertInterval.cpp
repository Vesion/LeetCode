#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& oi, vector<int>& ni) {
        vector<vector<int>> res;
        int i = 0;
        for (; i < oi.size(); ++i) {
            if (oi[i][1] < ni[0]) res.push_back(oi[i]);
            else if (oi[i][0] > ni[1]) break;
            else {
                ni[0] = min(ni[0], oi[i][0]);
                ni[1] = max(ni[1], oi[i][1]);
            }
        }
        res.push_back(ni);
        for (int j = i; j < oi.size(); ++j) res.push_back(oi[j]);
        return res;
    }
};


int main() {
    return 0;
}
