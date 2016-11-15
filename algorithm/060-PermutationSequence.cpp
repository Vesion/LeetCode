#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> 
#include <string>
using namespace std;

// Math : Canton Expression
// k = an*(n-1)! + an-1*(n-2)! + ... + ai*(i-1)! + ... + a2*1! + a1*0!
class Solution {
public:
    string getPermutation(int n, int k) {
        // initialize a dictionary that stores 1, 2, ..., n
        string dict(n, '0');
        iota(dict.begin(), dict.end(), '1');

        // build up a look-up factorial table, which stores (n-1)!, (n-2)!, ..., 1!, 0!
        vector<int> fact(n, 1);
        for (int i = n-3; i >= 0; --i)
            fact[i] = fact[i+1] * (n-i-1);

        // let k be zero based
        --k;

        string res(n, '0');
        for (int i = 0; i < n; ++i) {
            int select = k / fact[i];
            k %= fact[i];
            res[i] = dict[select];
            dict.erase(dict.begin()+select);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

