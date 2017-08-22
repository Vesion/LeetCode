#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : two passes
class Solution_1 {
public:
    string getHint(string secret, string guess) {
        vector<int> s(10, 0), g(10, 0);
        int A = 0, B = 0;
        for (int i = 0; i < (int)secret.size(); ++i) {
            if (secret[i] == guess[i]) ++A;
            else ++s[secret[i]-'0'], ++g[guess[i]-'0'];
        }
        for (int i = 0; i < 10; ++i)
            B += min(s[i], g[i]);
        return to_string(A) + "A" + to_string(B) + "B";
    }
};


// Solution 2 : one pass
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> count(10, 0);
        int n = secret.size();
        int A = 0, B = 0;
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) ++A;
            else {
                if (count[secret[i]-'0']++ < 0) ++B; // meet it in guess before
                if (count[guess[i]-'0']-- > 0) ++B; // meet it in secret before
            }
        }
        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};


int main() {
    return 0;
}
