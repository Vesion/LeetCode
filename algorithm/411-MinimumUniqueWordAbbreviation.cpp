#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The plain solution is very slow, because each time it gets a abbreviation, it will validate it in O(m*k*n), m is size of dictionary, k is average length of all words, n is length of target, it is O(2^n * m*k*n)

// Solution 1 : bitmap + dfs, skillful
// https://discuss.leetcode.com/topic/61457/c-bit-manipulation-dfs-solution
// https://discuss.leetcode.com/topic/61690/python-with-bit-masks
//
// Observation:
// 1. First of all, words in dictionary whose abbreviation may conflict with target's must have same length with target.
//
// 2. The number of all target's abbreviations is 2^n (same with subsets problem), so each abbreviation can be presented by an integer (bitmap) with
//      1 denotes this character isn't abbreviated
//      0 denotes this character is abbreviated
//
// 3. The valid abbreviation must include the different letter from word.
//      e.g. target is "apple", word is "apply", then the valid abbreviation must include 'e' ('e' must not be abbreviated), 
//          because 'e' is the only letter distinguishing these two.
//
// Steps:
// 1. For each dictionary word (of correct size), I create a diff-number whose bits tell me which of the word's letters differ from the target.
//
// 2. Then I go through the 2^n possible abbreviations, represented as number from 0 to 2^n-1. An abbreviation is valid if it doesn't match any dictionary word.
//    To check whether an abbreviation doesn't match a dictionary word,
//    I simply check whether the abbreviation number and the dictionary word's diff-number have a common 1-bit. 
//    Then from the valid abbreviations I find one that maximizes how much length it saves me. (the shortest one)
//
// 3. Reconstruct the result string with the bit mask integer we get above.
//
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int n = target.size();

        // step 1 : preprocess dictionary
        vector<int> diffs;
        for (string& word : dictionary) {
            if (word.size() != target.size()) continue;
            int diff = 0;
            for (int i = 0; i < n; ++i) {
                if (target[i] != word[i]) diff |= (1 << i);
            }
            diffs.push_back(diff);
        }
        
        // step 2 : generate abbreviations and find the shortest one
        int minLen = INT_MAX, minAbbr = 0;
        for (int i = 0; i < (1<<n); ++i) {
            // note: we here use a very quick method to compute length, it is not the length defined in problem description
            // e.g. abbbbbbbbbbc, one of its abbr is a10c, its length is 4, but we will get 3 here
            // it doesn't matter because we just compare lengths, and a string's abbr's length will never get larger than the string's
            int len = n;
            for (int twoones = 0b11; twoones < (1<<n); twoones <<= 1) {
                if ((i & twoones) == 0) --len;
            }
            if (len >= minLen) continue;

            bool conflict = false;
            for (int& diff : diffs) {
                if ((i & diff) == 0) { conflict = true; break; }
            }
            if (conflict) continue;

            minLen = len;
            minAbbr = i;
        }
        
        // step 3 : construct final result string using its bitmap
        string res;
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (((minAbbr>>i) & 1) == 1) {
                if (c) res += to_string(c);
                res += target[i];
                c = 0;
            }
            else ++c;
        }
        if (c) res += to_string(c);
        return res;
    }
};


int main() {
    Solution s;
    vector<string> d = {"plain", "amber", "blade"};
    cout <<s.minAbbreviation("apple", d) <<endl;;
    return 0;
}
