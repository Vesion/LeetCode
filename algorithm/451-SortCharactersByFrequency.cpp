#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <map> 
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) return "";
        unordered_map<char, int> m;
        for (char &c : s) m[c]++;
        multimap<int, char, greater<int>> d;
        for (auto &p : m) d.insert({p.second, p.first});
        string r;
        for (auto &p : d) r += string(p.first, p.second);
        return r;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort("abaaadcd") << endl;;
    return 0;
}
