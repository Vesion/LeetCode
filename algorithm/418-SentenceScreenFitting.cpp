#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> dp(n, 0); // dp[i] = the number of words can be fitting in one row when start with sentence[i]
        int res = 0;
        while (rows--) {
            int i = res % n;
            if (dp[i]) res += dp[i];
            else {
                int j = i, c = 0, len = 0;
                while (len + (int)sentence[j].size() <= cols) {
                    len += sentence[j].size() + 1;
                    if (++j == n) j = 0;
                    ++c;
                }
                res += c;
                dp[i] = c;
            }
        }
        return res / n;
    }
};


int main() {
    return 0;
}
