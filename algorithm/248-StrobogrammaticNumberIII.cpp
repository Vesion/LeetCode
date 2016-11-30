#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    char first[5] = {'0', '1', '8', '6', '9'};
    char second[5] = {'0', '1', '8', '9', '6'};

    int strobogrammaticInRange(string low, string high) {
        int m = low.size(), n = high.size();
        int res = 0;
        for (int len = m; len <= n; ++len) {
            if (m < len && len < n) { // for stros whose length between m+1 and n-1, calculate count directly
                if (len & 1) res += pow(5, len/2-1) * 12;
                else res += pow(5, len/2-1)*4;
            } else { // for length equal to m or n, generate stros one by one
                string num(len, '0');
                dfs(0, len-1, num, low, high, res);
            }
        }
        if (low == "0") ++res;
        return res;
    }

    void dfs(int start, int end, string& num, string& low, string& high, int& res) {
        if (start > end) {
            if (num.size() == low.size() && num < low) return;
            if (num.size() == high.size() && num > high) return;
            ++res;
            return;
        }
        for (int i = 0; i < 5; ++i) {
            if (start == 0 && i == 0) continue;
            if (start == end && i >= 3) break;
            num[start] = first[i];
            num[end] = second[i];
            dfs(start+1, end-1, num, low, high, res);
        }
    }
};

int main() {
    Solution s;
    cout << s.strobogrammaticInRange("0", "1680") << endl;
    return 0;
}
