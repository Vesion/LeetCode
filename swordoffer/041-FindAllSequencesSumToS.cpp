#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Solution 1 : two pointers, sliding window, O(S)
class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int S) {
        vector<vector<int>> res;
        int i = 1, j = 2;
        int sum = i+j;
        while (i <= S/2) {
            if (sum == S) {
                vector<int> r;
                for (int t = i; t <= j; ++t) r.push_back(t);
                res.push_back(r);
                sum += ++j;
            }
            else if (sum > S) sum -= i++;
            else sum += ++j;
        }
        return res;
    }
};


// Solution 2 : math
class Solution_2 {
public:
    vector<vector<int>> FindContinuousSequence(int S) {
        vector<vector<int>> res;
        for (int i = S/2+1; i >= 2; --i) {
            if (i&1) {
                if (S%i) continue;
                int lower = S/i-i/2, upper = S/i+i/2;
                if (lower < 1 || upper > S) continue;
                vector<int> r;
                for (int j = lower; j <= upper; ++j) r.push_back(j);
                res.push_back(r);
            } else {
                if ((S*10/i)%10 != 5) continue;
                int lower = S/i-i/2+1, upper = S/i+i/2;
                if (lower < 1 || upper > S) continue;
                vector<int> r;
                for (int j = lower; j <= upper; ++j) r.push_back(j);
                res.push_back(r);
            }
        }
        return res;
    }
};


int main() {
    Solution_2 s;
    auto r = s.FindContinuousSequence(3);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
