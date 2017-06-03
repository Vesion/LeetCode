#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int c = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = nums[j];
                ++c;
            }
            res = max(res, c);
        }
        return res;
    }
};


int main() {
    return 0;
}
