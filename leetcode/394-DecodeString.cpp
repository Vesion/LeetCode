#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// top-down parser
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return parse(s, i);
    }

    string parse(const string& s, int& i) {
        string res;
        int num = 0;
        for (; i < s.size(); ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num*10 + (c-'0');
            } else if (c == '[') {
                string t = parse(s, ++i);
                for (int k = 0; k < num; ++k) res += t;
                num = 0;
                // ++i will skip ']'
            } else if (c == ']') {
                break;
            } else {
                res += c;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    cout << s.decodeString("a2[a]2[b]cc") << endl;
    return 0;
}

