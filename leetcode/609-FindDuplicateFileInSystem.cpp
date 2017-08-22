#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <sstream> 
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for (auto& path : paths) {
            istringstream in(path);
            string directory; in >> directory;
            string file;
            while (in >> file) {
                auto p = file.find_first_of('(');
                string name = file.substr(0, p);
                string content = file.substr(p);
                m[content].push_back(directory+"/"+name);
            }
        }
        vector<vector<string>> res;
        for (auto& p : m) if (p.second.size() > 1) res.push_back(p.second);
        return res;
    }
};


int main() {
    return 0;
}
