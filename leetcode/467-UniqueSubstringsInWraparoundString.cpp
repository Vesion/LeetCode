#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0); // dp[i] means the max length of substring ending with 'a'+i
        int len = 0;
        for (int i = 0; i < (int)p.size(); ++i) {
            if (i > 0 && (p[i]-p[i-1]+26) % 26 == 1) ++len;
            else len = 1;
            int c = p[i]-'a';
            dp[c] = max(dp[c], len);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};


int main() {
    return 0;
}
