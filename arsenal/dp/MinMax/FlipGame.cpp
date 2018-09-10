#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// https://leetcode.com/problems/flip-game-ii/
// You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

// top-down + memo
class Solution {
public:
    bool canWin(string s) {
        unordered_map<string, bool> memo;
        return win(s, memo);
    }
    
    bool win(string& s, unordered_map<string, bool>& memo) {
        if (memo.count(s)) return memo[s];
        bool res;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == '+' && s[i-1] == '+') {
                s[i] = s[i-1] = '-';
                res = !win(s, memo);
                s[i] = s[i-1] = '+';
                if (res) break;
            }
        }
        memo[s] = res;
        return res;
    }
};


int main() {
    return 0;
}
