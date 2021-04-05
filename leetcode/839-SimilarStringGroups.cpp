#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// union find
class Solution {
public:
    vector<int> root;
    int count;
    int find(int x) {
        return x == root[x] ? x : root[x] = find(root[x]);
    }
    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            root[rx] = ry;
            --count;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        root.resize(n); iota(root.begin(), root.end(), 0);
        count = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (similar(strs[i], strs[j])) link(i, j);
            }
        }
        return count;
    }

    bool similar(const string& x, const string& y) {
        int t = 0;
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] != y[i]) ++t;
            if (t > 2) return false;
        }
        return true;
    }
};

int main() {
}
