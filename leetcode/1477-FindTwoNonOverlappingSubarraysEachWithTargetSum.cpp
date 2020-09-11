#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int n = arr.size();

        int sum = 0;
        vector<int> len(n, n+1);
        for (int i = 0, j = 0; j < n; j++) {
            sum += arr[j];
            while (sum > target && i < j) sum -= arr[i++];
            if (sum == target) len[j] = j-i+1;
        }

        int res = n+1;
        int dp = n+1;
        for (int i = 0; i < n; ++i) {
            if (i-len[i] >= 0) res = min(res, len[i-len[i]] + len[i]);
            dp = min(dp, len[i]);
            len[i] = dp;
        }
        return res > n ? -1 : res;
    }
};

int main() {
    return 0;
}

