#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Codec {
public:
    string encode(vector<string>& strs) {
        string res;
        for (string& s : strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < (int)s.size()) {
            int j = s.find_first_of('#', i);
            int len = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j+1, len));
            i = j+1+len;
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
