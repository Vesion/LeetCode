#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        if (sentence.empty() || rows == 0 || cols == 0) return 0;
        int n = sentence.size();
        vector<int> dp(n, 0); // dp[i] means the number of words a row can contain, when start with sentence[i]
        int count = 0; // the total number of words in screen, count/n is the final result

        for (int i = 0; i < rows; ++i) {
            int start = count % n; // the start word of this row
            if (dp[start]) count += dp[start];
            else {
                int i = start;
                int len = 0;
                int c = 0;
                while (len < cols) {
                    if (len + (int)sentence[i].size() > cols) break;
                    len += sentence[i].size() + 1;
                    i = (i+1) % n;
                    ++c;
                }
                count += c;
                dp[start] = c;
            }
        }
        return count / n;
    }
};


int main() {
    Solution s;
    return 0;
}
