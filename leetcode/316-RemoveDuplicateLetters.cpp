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
        vector<int> m(128, 0);
        for (char& c : s) m[c]++;
        string res;
        vector<bool> inres(128, false);
        for (char& c : s) {
            --m[c];
            if (inres[c]) continue;
            while (!res.empty() && c < res.back() && m[res.back()] >= 1) {
                inres[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            inres[c] = true;
        }
        return res;
    }
};


int main() {
    return 0;
}

