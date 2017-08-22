#include <iostream>
#include <string>
#include <vector> 
using namespace std;

/*
 * Very classical string match problem
 * Solution-1 : Brute-Force O(m * n)
 * Solution-2 : KMP O(n + m)
 * Solution-3 : Boyer-Mooer O(n / m)
 */

// Solution 1 : naive, O(m*n)
class Solution {
public:
    int strStr(string s, string p) {
        if (p.empty()) return 0;
        int m = p.size(), n = s.size();
        for (int i = 0; i <= n - m; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (s[i+j] != p[j]) break;
            }
            if (j == m) return i;
        }
        return -1;
    }
};


// Solution 2 : KMP, O(n)
class Solution_2 {
public:
    int strStr(string s, string p) {
        if (p.empty()) return 0;
        int m = p.size(), n = s.size();
        vector<int> prefix(m, 0);
        int j = 0;
        for (int i = 1; i < m; ++i) {
            while (j > 0 && p[i] != p[j]) j = prefix[j-1];
            if (p[i] == p[j]) ++j;
            prefix[i] = j;
        }
        
        j = 0;
        for (int i = 0; i < n; ++i) {
            while (j > 0 && s[i] != p[j]) j = prefix[j-1];
            if (s[i] == p[j]) ++j;
            if (j == m) return i-j+1;
        }
        return -1;
    }
};


int main() {
    return 0;
}
