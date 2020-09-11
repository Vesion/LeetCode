#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res;
        vector<string> subs(S.size());
        vector<bool> r(S.size(), false);
        for (int i = 0; i < indexes.size(); ++i) {
            const int index = indexes[i];
            const string& s = sources[i];
            const string& t = targets[i];
            if (S.substr(index, s.size()) == s) {
                subs[index] = t;
                for (int j = index; j < index + s.size(); ++j) r[j] = true;
            }
        }
        for (int i = 0; i < S.size(); ++i) {
            if (!subs[i].empty()) res += subs[i];
            if (r[i]) continue;
            res += S[i];
        }
        return res;
    }
};


int main() {
    return 0;
}
