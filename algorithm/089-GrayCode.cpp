#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// use n codes to generate next n codes
//      00
//      01
//      -- symmetric other than the most significant bit
//      11
//      10

// Solution 1 : recursive, backtracking
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int num = 0;
        dfs(num, n, res);
        return res;
    }
    
    void dfs(int& num, int n, vector<int>& res) {
        if (n == 0) {
            res.push_back(num);
            return;
        }
        dfs(num, n-1, res);
        num ^= (1 << (n-1));
        dfs(num, n-1, res);
    }
};

// Solution 2 : iterative
class Solution_2 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 0; i < n; ++i) {
            for (int j = res.size()-1; j >= 0; --j) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};


// Solution 3 : formula, the gray code of a decimal number n is n ^ (n>>1)
class Solution_3 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < 1<<n; ++i)
            res.push_back(i ^ (i>>1));
        return res;
    }
};


int main() {
    return 0;
}
