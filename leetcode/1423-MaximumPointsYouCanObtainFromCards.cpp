#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        const int n = c.size();
        int res = 0;
        int i = k-1, j = k-1;
        int sum = 0;
        while (i != -(k+1)) {
            sum += c[i < 0 ? n+i : i];
            --i;
            if (j-i > k) {
                sum -= c[j < 0 ? n+j : j];
                --j;
            }
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
}
