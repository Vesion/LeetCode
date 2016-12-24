#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The core idea is to combine 320-GeneralizedAbbreviation and 408-ValidWordAbbreviation.

// The plain solution is very slow, because each time it gets a abbreviation, it will validate it in O(m*k*n), m is size of dictionary, k is average length of all words, n is length of target.
// So, the it is O(2^n * m*k*n)
class Solution_0 {
public:
    string res;
    int resLen = INT_MAX;

    string minAbbreviation(string target, vector<string>& dictionary) {
        if (target.empty()) return target;
        dfs(target, 0, 0, "", 0, dictionary);
        return res;
    }

    void dfs(string& target, int start, int num, string path, int len, vector<string>& dictionary) {
        if (start == (int)target.size()) {
            if (num) { path += to_string(num); ++len; }
            for (string& word : dictionary) if (word.size() == target.size() && isAbbr(word, path)) return;
            if (len < resLen) {
                res = path;
                resLen = len;
            }
            return;
        }

        dfs(target, start+1, num+1, path, len, dictionary);

        if (num) { path += to_string(num); ++len; }
        dfs(target, start+1, 0, path+target[start], len+1, dictionary);
    }

    bool isAbbr(string& word, string& abbr) {
        if (word.empty() && abbr.empty()) return true;
        int m = word.size(), n = abbr.size();
        if (m < n) return false;
        int i = 0, j = 0;
        while (j < n) {
            if (isalpha(abbr[j])) {
                if (word[i++] != abbr[j++]) return false;
            } else {
                if (abbr[j] == '0') return false;
                int num = 0;
                while (j < n && isdigit(abbr[j])) num = num*10 + (abbr[j++]-'0');
                i += num;
            }
        }
        return i == m;
    }
};



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
        int bn = 1 << n;
        vector<int> diffs;

        // step 1 : preprocess dictionary
        for (string& word : dictionary) {
            if (word.size() != target.size()) continue;
            int diff = 0;
            for (int i = 0; i < n; ++i)
                diff = (diff << 1) | (target[i] != word[i]);
            diffs.push_back(diff);
        }

        // step 2 : generate abbreviations and find the minimum
        int minAbbr = 0, minLen = INT_MAX;
        for (int i = 0; i < bn; ++i) {
            // get abbreviation's length
            int len = n;
            for (int twoones = 0b11; twoones < bn; twoones <<= 1) {
                if ((i & twoones) == 0) --len;
            }
            if (len >= minLen) continue;
            bool conflict = false;
            for (int diff : diffs) {
                if ((i & diff) == 0) { conflict = true; break; }
            }
            if (conflict) continue;
            minLen = len;
            minAbbr = i;
        }

        // step 3 : reconstruct result string from bit mask
        string res; 
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if ((minAbbr >> (n-1-i)) & 1) {
                if (num) res += to_string(num);
                num = 0;
                res += target[i];
            } else ++num;
        }
        if (num) res += to_string(num);
        return res;
    }
};

int main() {
    Solution s;
    vector<string> d = {"plain", "amber", "blade"};
    cout <<s.minAbbreviation("apple", d) <<endl;;
    return 0;
}

