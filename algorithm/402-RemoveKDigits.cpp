#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Similar to '321-CreateMaximumNumber'
// greedy, minimum stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        k = n - k;
        string result(k, '0');
        int t = 0;
        for (int i = 0; i < n; ++i) {
            while (n-i+t > k && t > 0 && result[t-1] > num[i]) --t;
            if (t < k) result[t++] = num[i];
        }
        int i = 0;
        while (result[i] == '0') ++i;
        result = result.substr(i);
        return result.empty() ? "0" : result;
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits("10200", 1) <<endl;
    return 0;
}
