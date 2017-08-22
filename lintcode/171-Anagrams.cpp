#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> m;
        for (auto &s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            m[k].push_back(s);
        }

        vector<string> result;
        for (auto &p : m) {
            if (p.second.size() > 1) 
                result.insert(result.end(), p.second.begin(), p.second.end());
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"lint", "intl", "inlt", "code"};
    auto r = s.anagrams(strs);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
