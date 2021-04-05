#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

// binary search
class Solution {
public:
    int sum_w;
    vector<int> ws;

    Solution(vector<int>& w) {
        ws = w;
        partial_sum(ws.begin(), ws.end(), ws.begin());
        sum_w = ws.back();
    }

    int pickIndex() {
        int t = rand() % sum_w + 1;
        return lower_bound(ws.begin(), ws.end(), t) - ws.begin();
    }
};


int main() {

}