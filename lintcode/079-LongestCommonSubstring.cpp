#include <iostream>
#include <vector>
using namespace std;


// Differenct with 'Longest Common Sequence (LCS)' problem
// DP Solution, O(m*n):
//      First find the longest common suffix of all pairs of prefixes of the strings:
//          LCSuffix(i, j) = LCSuffix(i-1, j-1) + 1     if A[i] == B[j]
//                           0                          if A[i] != B[j]
//      Then the longest common substring is the maximal of these longest common suffixes:
//          LCSubstr(A, B) = max{ LCSuffix(i, j) }
class Solution {
public:
    int longestCommonSubstring(string &A, string &B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> lcsuffix(m+1, vector<int>(n+1, 0));
        int lcsubstr = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                lcsuffix[i][j] = (A[i-1] == B[j-1] ? lcsuffix[i-1][j-1]+1 : 0);
                lcsubstr = max(lcsubstr, lcsuffix[i][j]);
            }
        }
        return lcsubstr;
    } 
};


// Suffix tree Solution, O(m+n):
// http://www.geeksforgeeks.org/suffix-tree-application-5-longest-common-substring-2/


int main() {
    Solution s;
    string A = "ABCD", B = "CBCE";
    cout << s.longestCommonSubstring(A, B) << endl;;
    return 0;
}
