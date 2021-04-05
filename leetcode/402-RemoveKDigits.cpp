#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy, stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int m = n-k;
        string res;
        for (int i = 0, j = 0; i < n; ++i) {
            while (!res.empty() && num[i] < res.back() && res.size()+n-i > m)
                res.pop_back();
            if (res.size() < m) res.push_back(num[i]);
        }
        auto it = res.find_first_not_of('0');
        if (it == string::npos) return "0";
        return res.substr(it);
    }
};


int main() {
    Solution s;
    cout << s.removeKdigits("100", 2) << endl;
    return 0;
}
