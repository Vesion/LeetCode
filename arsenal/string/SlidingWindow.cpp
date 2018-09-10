#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <unordered_map> 
using namespace std;

// Sliding Window (hash table + two pointers) is a powerful method to solve substring problems:
//
//      For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions.
//
// Here are some examples:


// 003
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
int lengthOfLongestSubstring(string s) {
    vector<int> m(128, 0);
    int i = 0, j = 0, c = 0;
    int res = 0;
    while (j < (int)s.size()) {
        if (m[s[j++]]++ == 1) ++c;
        while (c == 1) {
            if (m[s[i++]]-- == 2) --c;
        }
        res = max(res, j-i);
    }
    return res;
}


// 030
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// similar to 438-FindAllAnagramsInAString, maintain a fixed-size window, but here we need to consider one word as a unit
vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> dict;
    for (string& w : words) dict[w]++;
    int wlen = words[0].size();
    int n = s.size(), m = words.size()*wlen;

    vector<int> res;
    for (int start = 0; start < wlen; ++start) {
        unordered_map<string, int> f = dict;
        int c = words.size();
        int i = start, j = start;
        while (j+wlen <= n) {
            // extend window
            if (f[s.substr(j, wlen)]-- > 0) --c;
            j += wlen;

            // include all words in dict
            if (c == 0) res.push_back(i);

            // if size reaches m, fix it
            if (j-i == m) {
                if (f[s.substr(i, wlen)]++ >= 0) ++c;
                i += wlen;
            }
        }
    }
    return res;
}


// 076
// https://leetcode.com/problems/minimum-window-substring/
// Find the shortest substring which contains all characters of given string t.
string minWindow(string s, string t) {
    vector<int> m(128, 0);
    for (char c : t) m[c]++;
    int i = 0, j = 0, c = t.size();
    int len = INT_MAX, start = 0;
    while (j < (int)s.size()) {
        if (m[s[j++]]-- > 0) --c;
        while (c == 0) { // find a valid substring
            if (j-i < len) { len = j-i; start = i; }
            if (m[s[i++]]++ == 0) ++c; // shrink window to turn it into an invalid substring
        }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
}


// 159
// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
int lengthOfLongestSubstringTwoDistinct(string s) {
    vector<int> m(128, 0);
    int i = 0, j = 0, c = 0;
    int res = 0;
    while (j < (int)s.size()) {
        if (m[s[j++]]++ == 0) ++c;
        while (c > 2)
            if (m[s[i++]]-- == 1) --c;
        res = max(res, j-i);
    }
    return res;
}


// 209
// https://leetcode.com/problems/minimum-size-subarray-sum/
int minSubArrayLen(int s, vector<int>& nums) {
    int i = 0, j = 0, sum = 0;
    int res = INT_MAX;
    while (j < (int)nums.size()) {
        sum += nums[j++];
        while (sum >= s) {
            res = min(res, j-i);
            sum -= nums[i++];
        }
    }
    return res == INT_MAX ? 0 : res;
}


// 340
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
int lengthOfLongestSubstringKDistinct(string s, int k) {
    vector<int> m(128, 0);
    int i = 0, j = 0, c = 0;
    int res = 0;
    while (j < (int)s.size()) {
        if (m[s[j++]]++ == 0) ++c;
        while (c > k)
            if (m[s[i++]]-- == 1) --c;
        res = max(res, j-i);
    }
    return res;
}


// 424
// https://leetcode.com/problems/longest-repeating-character-replacement/
int characterReplacement(string s, int k) {
    vector<int> m(128, 0);
    int i = 0, j = 0;
    int res = 0;
    while (j < (int)s.size()) {
        m[s[j++]]++;
        while (j-i-*max_element(m.begin(), m.end()) > k) m[s[i++]]--;
        res = max(res, j-i);
    }
    return res;
}
// faster solution
int characterReplacement_On(string s, int k) {
    vector<int> m(128, 0);
    int i = 0, j = 0, c = 0;
    while (j < (int)s.size()) {
        c = max(c, ++m[s[j++]]);
        if (j-i-c > k) m[s[i++]]--;
    }
    return s.size()-i;
}


// 438
// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// maintain a fixed-size window, move from front to end, use count to check validity
vector<int> findAnagrams(string s, string p) {
    vector<int> m(128, 0);
    for (char c : p) m[c]++;
    int i = 0, j = 0, c = p.size();
    vector<int> res;
    while (j < (int)s.size()) {
        if (m[s[j++]]-- > 0) --c;
        if (c == 0) res.push_back(i);
        if (j-i == (int)p.size() && m[s[i++]]++ >= 0) ++c;
    }
    return res;
}


// 487
// https://leetcode.com/problems/max-consecutive-ones-ii/
// if we receive infinite datastream, we need to sotre positions
int findMaxConsecutiveOnes(vector<int>& nums) {
    int i = 0, j = 0;
    int c = 0;
    int k = 1; // we can flip 0 at most k times
    int res = 0;
    queue<int> zeroes; // we use a queue to maintain k indexes of zeroes
    while (j < (int)nums.size()) {
        if (nums[j++] == 0) {
            ++c;
            zeroes.push(j);
        }
        if (c > k) {
            i = zeroes.front(); zeroes.pop();
            --c;
        }
        res = max(res, j-i);
    }
    return res;
}


int main() {
    return 0;
}
