#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <sstream> 
using namespace std;

// Solution 1 : common backtracking without memoization, O(2^n)
class Solution_1 {
public:
    bool canWin(string s) {
        int n = s.size();
        if (n < 2) return false;
        return win(s);
    }

    bool win(string& s) {
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == '+' && s[i-1] == '+') {
                s[i] = s[i-1] = '-';
                if (!win(s)) {
                    s[i] = s[i-1] = '+';
                    return true;
                }
                s[i] = s[i-1] = '+';
            }
        }
        return false;
    }
};


// Solution 2 : backtracking with memoization, O(2^n)
class Solution_2 {
public:
    unordered_map<string, bool> m;

    bool canWin(string s) {
        int n = s.size();
        if (n < 2) return false;
        return win(s);
    }

    bool win(string& s) {
        if (m.count(s)) return m[s];
        bool res = false;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == '+' && s[i-1] == '+') {
                s[i] = s[i-1] = '-';
                res = !win(s);
                s[i] = s[i-1] = '+';
                if (res) break;
            }
        }
        m[s] = res;
        return res;
    }
};


// Solution 3 : Awesome game theory! dp, O(n^2)
// https://discuss.leetcode.com/topic/27282/theory-matters-from-backtracking-128ms-to-dp-0ms
class Solution {
public:
    bool canWin(string s) {
        replace(s.begin(), s.end(), '-', ' ');
        istringstream in(s);
        int G = 0;
        vector<int> g;
        for (string t; in >> t; ) {
            int p = t.size();
            while ((int)g.size() <= p) {
                string x = t;
                int i = 0, j = g.size() - 2;
                while (i <= j)
                    x[g[i++] ^ g[j--]] = '-';
                g.push_back(x.find('+'));
            }
            G ^= g[p];
        }
        return G;
    }
};




int main() {
    Solution_1 s;
    cout << s.canWin("+++++") << endl;
    return 0;
}
