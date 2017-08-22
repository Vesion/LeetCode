#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy, stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.empty()) return num;
        int n = num.size();
        k = n-k;
        string res(k, 0);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j != 0 && num[i] < res[j-1] && n-i+j > k) --j;
            if (j < k) res[j++] = num[i];
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
