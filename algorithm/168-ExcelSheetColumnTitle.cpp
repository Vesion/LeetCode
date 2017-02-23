#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Convert decimal to base-26
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            // why --n? 
            // because 'A' = 1, not = 0
            // i.e. n = [1,26], if n%26 directly, we get [1,2,..,0], then we get [B,C,...,Z]
            //      so, after --n, we get [0,1,...,25], then we can get [A,B,...Z]
            --n;
            res = (char)('A' + n%26) + res;
            n /= 26;
        }
        return res;
    }
};


int main() {
    return 0;
}
