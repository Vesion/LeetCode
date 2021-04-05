#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int minDeletions(string s) {
        int m[26] = {};
        for (char c : s) ++m[c-'a'];
        vector<int> d;
        for (int i = 0; i < 26; ++i) if (m[i]) d.push_back(m[i]);
        if (d.size() < 2) return 0;
        sort(d.begin(), d.end());
        int l = 0, res = 0;
        for (int i = d.size()-2; i >= 0; --i) {
            if (d[i] >= d[i+1]) {
                int nd = max(0, d[i+1]-1);
                res += (d[i]-nd);
                d[i] = nd;
            }
        }
        return res;
    }
};

int main() {
}