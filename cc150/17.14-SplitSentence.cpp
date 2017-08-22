#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Page 327
// Given a dictionary and a sentence, try to split sentence into several words, there may be some invalid words after splitting, what is the shortest length of them?

// backtracking + memo
// for each character, we have two choices:
//      split after here, extract current tracking word, check if it is a valid word
//      don't split, append this character to current tracking word
class Solution {
public:
    int split(unordered_set<string>& dict, string& sentence) {
        int n = sentence.size();
        vector<int> memo(n, 0);
        return helper(sentence, 0, 0, dict, memo);
    }

    int helper(string& s, int start, int end, unordered_set<string>& dict, vector<int>& memo) {
        if (end == (int)s.size()) return end - start;
        if (memo[start]) return memo[start];

        // split after here to extract s[start, end] as a word, and check if it is a valid word
        int extract = (dict.count(s.substr(start, end-start+1)) ? 0 : end-start+1) + helper(s, end+1, end+1, dict, memo);

        // remain this character to extend s[start, end]
        int extend = helper(s, start, end+1, dict, memo);

        int res = min(extract, extend);
        memo[start] = res;
        return res;
    }
};


int main() {
    Solution s;
    unordered_set<string> dict = {"hello", "world"};
    string sentence = "helloooowwwworld";
    cout << s.split(dict, sentence) << endl;
    return 0;
}
