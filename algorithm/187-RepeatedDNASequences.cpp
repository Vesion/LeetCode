#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> res;
        int key = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            key = (key << 3) & ((1<<30)-1);
            key |= s[i] & 7;
            if (m[key]++ == 1) res.push_back(s.substr(i-9, 10));
        }
        return res;
    }
};

int main() {
    Solution s;
    auto r = s.findRepeatedDnaSequences("AAAAAAAAAAAAA");
    for (auto& e : r) cout << e << endl; cout << endl; 
    return 0;
}

