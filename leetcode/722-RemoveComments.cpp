#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        res.reserve(source.size());
        bool inb = false;
        string line;
        for (const string& s : source) {
            for (int i = 0; i < s.size(); ) {
                if (i < s.size() - 1) {
                    if (s[i] == '/' && s[i+1] == '/' && !inb) {
                        break;
                    }
                    if (s[i] == '/' && s[i+1] == '*' && !inb) {
                        i += 2;
                        inb = true;
                        continue;
                    }
                    if (s[i] == '*' && s[i+1] == '/' && inb) {
                        i += 2;
                        inb = false;
                        continue;
                    }
                }
                if (!inb) line.push_back(s[i]);
                ++i;
            }
            if (!inb && !line.empty()) {
                res.push_back(line);
                line.clear();
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> c = { "a//*b/*/c","blank","d/*/e/*/f" };
    auto r = s.removeComments(c);
    for (auto& e : r) cout << e << endl; cout << endl;
    return 0;
}
