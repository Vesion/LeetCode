#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Min sum
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        for (int c : cardPoints) sum += c;
        int s = 0, t = cardPoints.size() - k;
        int min_s = sum;
        for (int i = 0; i < cardPoints.size(); ++i) {
            s += cardPoints[i];
            if (i >= t) s -= cardPoints[i-t];
            if (i >= t-1) min_s = min(min_s, s);
        }
        return sum - min_s;
    }
};

// Max sum
class Solution2 {
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
