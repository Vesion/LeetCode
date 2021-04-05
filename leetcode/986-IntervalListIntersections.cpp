#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Just like merge sort, use two pointers to merge sorted list
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < l1.size() && j < l2.size(); ) {
            int begin = max(l1[i][0], l2[j][0]);
            int end = min(l1[i][1], l2[j][1]);
            if (begin <= end) res.push_back({begin, end});
            if (l1[i][1] < l2[j][1]) ++i;
            else ++j;
        }
        return res;
    }
};

int main() {

}
