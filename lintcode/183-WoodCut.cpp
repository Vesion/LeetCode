#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int woodCut(vector<int> L, int k) {
        if (L.empty()) return 0;
        int maxWood = *max_element(L.begin(), L.end());
        int left = 1, right = maxWood;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int kc = 0;
            for (int l : L) kc += l/mid;
            if (kc < k) right = mid-1;
            else left = mid+1;
        }
        return right;
    } 
};

int main() {
    Solution s;
    vector<int> L = {};
    cout << s.woodCut(L, 2) << endl;
    return 0;
}
