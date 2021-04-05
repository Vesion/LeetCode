#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// stack, greedy, similar to 402-RemoveKDigits
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[128] = {};
        for (char c : s) ++m[c];
        string res;
        bool used[128] = {};
        for (char c : s) {
            --m[c];
            if (used[c]) continue;
            // if c is smaller than characters before, and we have enough
            // these characters after, it will be safe to throw them away.
            while (!res.empty() && c < res.back() && m[res.back()] >= 1) {
                used[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            used[c] = true;
        }
        return res;
    }
};


int main() {
    return 0;
}

