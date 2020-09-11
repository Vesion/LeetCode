#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

// binary search
class Solution {
public:
    vector<int> acc_w;
    int max_acc_w;

    Solution(vector<int>& w) {
        acc_w.resize(w.size());
        for (int i = 0; i < w.size(); ++i) {
            acc_w[i] = (i > 0 ? acc_w[i-1] : 0) + w[i];
        }
        max_acc_w = acc_w.back();
    }

    int pickIndex() {
        int t = rand() % max_acc_w + 1;
        return lower_bound(acc_w.begin(), acc_w.end(), t) - acc_w.begin();
    }
};

int main() {

}