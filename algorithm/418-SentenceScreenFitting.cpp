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
        int count = 0, i = 0;
        while (rows--) {
            if (dp[i]) {
                count += dp[i];
                i = (i+dp[i]) % n;
            } else {
                int c = 0, j = i, len = 0;
                while (len + (int)sentence[j].size() <= cols) {
                    len += sentence[j].size()+1;
                    j = (j+1)%n;
                    ++c;
                }
                count += c;
                dp[i] = c;
                i = j;
            }
        }
        return count / n;
    }
};


int main() {
    return 0;
}
