#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : use n codes to generate next n codes
//      00
//      01
//      -- symmetric other than the most significant bit
//      11
//      10
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if (n == 0) return res;
        for (int i = 0; i < n; ++i) {
            for (int j = (int)res.size()-1; j >= 0; --j)
                res.push_back(res[j] | (1 << i));
        }
        return res;
    }
};


// Solution 2 : formula, the gray code of a decimal number n is n ^ (n>>1)
class Solution_2 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < 1<<n; ++i)
            res.push_back(i ^ (i>>1));
        return res;
    }
};


int main() {
    Solution s;
    auto r = s.grayCode(4);
    for (auto& e : r) cout << e << " "; cout << endl; 
    Solution_2 s2;
    auto r2 = s2.grayCode(4);
    for (auto& e : r2) cout << e << " "; cout << endl; 
    return 0;
}

