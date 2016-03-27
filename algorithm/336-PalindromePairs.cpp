#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

bool isPalindrome(string& s) {
    int l = 0, r = s.size()-1;
    while (l <= r && s[l] == s[r]) ++l, --r;
    return l >= r;
}


// Solution 0 : naive brute-force, O(n^2*k) time, n is size of words array, k is average length of all words
// for each word, iterate all other words, check if concatenation of them is a palindrome
// we do not implement here


// Solution 1 : map and two pointers, O(n*k^2) time
// This solution improve Solution 0, by speed up the find process using map
vector<vector<int>> palindromePairs(vector<string>& words) {
    int n = words.size();
    unordered_map<string, int> m; 
    vector<vector<int>> result;
    for (int i = 0; i < n; ++i) {
        string w = words[i];
        reverse(w.begin(), w.end());
        m[w] = i;
    }

    if (m.count("")) { // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        for (int i = 0; i < n; ++i) 
            if (isPalindrome(words[i]) && i != m[""]) result.push_back({m[""], i});
    }
    for (int i = 0; i < n; ++i) {
        int wn = words[i].size();
        for (int j = 0; j < wn; ++j) {
            string left = words[i].substr(0, j);
            string right = words[i].substr(j, wn-j);
            if (m.count(left) && isPalindrome(right) && m[left] != i)
                result.push_back({i, m[left]});
            if (m.count(right) && isPalindrome(left) && m[right] != i)
                result.push_back({m[right], i});
        }
    }
    return result;
}


// Solution 2 : Trie, O(n*k^2) time
// https://leetcode.com/discuss/91429/solution-with-structure-total-number-words-average-length


int main() {
    vector<string> words = {"", "abcd", "dcba", "lls", "s", "sssll"};
    auto r = palindromePairs(words);
    for (auto i : r) { for (auto j : i) cout << j << " "; cout << endl; }
    return 0;
}
