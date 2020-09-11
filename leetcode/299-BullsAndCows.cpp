#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        int c[10] = {0};
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++a;
            else {
                if (c[secret[i]-'0']++ < 0) ++b;
                if (c[guess[i]-'0']-- > 0) ++b;
            }
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};


int main() {
    return 0;
}
