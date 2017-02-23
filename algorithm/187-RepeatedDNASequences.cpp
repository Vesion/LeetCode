#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

// bitmap, use 3bits to represent a character, so we need 30bits to represent a sequence
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        int key = 0;
        vector<string> res;
        for (int i = 0; i < (int)s.size(); ++i) {
            key = ((key << 3) & ((1<<30)-1)) | (s[i] & 0b111);
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

