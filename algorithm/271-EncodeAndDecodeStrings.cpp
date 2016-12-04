#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        string res;
        for (string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<string> res;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int split = s.find_first_of("#", i);
            int len = stoi(s.substr(i, split-i));
            i = split+1;
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};


int main() {
    Codec c;
    vector<string> s = {"你好", "world", "u"};
    string ec = c.encode(s);
    cout << ec << endl;
    auto r = c.decode(ec);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
