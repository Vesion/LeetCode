#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        // dp[i] = the number of words can be fit in a row if the row starts with sentence[i]
        vector<int> dp(n, 0);
        int words = 0;  // total number of words has been printed
        while (rows--) {
            int i = words % n;  // this row starts with sentence[i]
            if (!dp[i]) {
                int j = i, len = 0;
                while (len + sentence[j].size()  <= cols) {
                    len += sentence[j].size() + 1;
                    j = (j+1)%n;
                    ++dp[i];
                }
            }
            words += dp[i];
        }
        return words/n;
    }
};


int main() {
    return 0;
}
