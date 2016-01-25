#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> maps;
    for (string str : strs) {
        string copy(str);
        sort(copy.begin(), copy.end());
        maps[copy].push_back(str);
    }
    for (auto it  = maps.begin(); it != maps.end(); ++it) {
        sort(it->second.begin(), it->second.end());
        result.push_back(it->second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result = groupAnagrams(strs);
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
