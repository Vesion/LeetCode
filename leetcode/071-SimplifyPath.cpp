#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        string file;
        vector<string> st;
        while (getline(ss, file, '/')) {
            if (file.empty() || file == ".") continue;
            if (file == "..") {
                if (!st.empty()) st.pop_back();
            }
            else st.push_back(file);
        }
        if (st.empty()) return "/";
        string res;
        for (string& f : st) res += "/" + f;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("");
    return 0;
}

