#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        if (S.empty() || K <= 0) return "";
        int count = 0;
        for (int i = S.size()-1; i >= 0; --i) {
            if (isalnum(S[i])) {
                res += toupper(S[i]);
                ++count;
            }
            if (count == K) {
                res += '-';
                count = 0;
            }
        }
        if (!res.empty() && res.back() == '-') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.licenseKeyFormatting("---", 3) << endl;;

    return 0;
}
