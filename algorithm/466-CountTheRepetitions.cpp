#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 0 : brute-force, O(n1*l1), l1 is the length of s1, TLE
// similar to 392-IsSubsequence
class Solution_0 {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size(), l2 = s2.size();
        int j = 0, c = 0;
        for (int k = 0; k < n1; ++k) {
            for (int i = 0; i < l1; ++i) {
                if (s1[i] == s2[j]) {
                    if (++j == l2) {
                        ++c;
                        j = 0;
                    }
                }
            }
        }
        return c / n2;
    }
};


// Solution 1 : dp, find the repeat pattern
// https://discuss.leetcode.com/topic/72105/c-solution-inspired-by-70664914-with-organized-explanation
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<int> repeatCount(l2+1, 0), nextIndex(l2+1, 0);
        int j = 0, c = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < l1; ++i) {
                if (s1[i] == s2[j]) {
                    if (++j == l2) {
                        ++c;
                        j = 0;
                    }
                }
            }
            repeatCount[k] = c;
            nextIndex[k] = j;
            for (int s = 0; s < k; ++s) {
                if (nextIndex[s] == j) {
                    int prefixCount = repeatCount[s];
                    int patternCount = (repeatCount[k]-repeatCount[s]) * (n1-s) / (k-s);
                    int suffixCount = repeatCount[s + (n1-s)%(k-s)] - repeatCount[s];
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }
        return c / n2;
    }
};


int main() {
    Solution s;
    cout << s.getMaxRepetitions("niconiconi", 99981, "nico", 81) <<endl;
    return 0;
}
