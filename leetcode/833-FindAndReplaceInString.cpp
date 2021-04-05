#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res;
        int n = S.size();
        vector<string> subs(n);
        vector<bool> f(n, false);
        for (int k = 0; k < indexes.size(); ++k) {
            int i = indexes[k];
            const string& src = sources[k], tgt = targets[k];
            if (S.find(src, i) == i) {
                subs[i] = tgt;
                for (int j = i; j < i+src.size(); ++j) f[j] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!f[i]) res += S[i];
            if (!subs[i].empty()) res += subs[i];
        }
        return res;
    }
};


int main() {
    return 0;
}
