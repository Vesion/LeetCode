#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        vector<int> m(10, -1);
        m[0] = 0, m[1] = 1, m[6] = 9, m[8] = 8, m[9] = 6;
        int n = num.size();
        for (int i = 0; i <= n/2; ++i) {
            int c = num[i]-'0';
            if (m[c] == -1 || num[n-i-1] != m[c]+'0') return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}
