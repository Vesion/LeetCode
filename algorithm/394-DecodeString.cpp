#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Top-down parser
class Solution {
public:
    string decodeString(string s) {
        int cur = 0;
        return parse(s, cur);
    }    

    string parse(string& s, int& cur) {
        string res;
        int num = 0;
        while (cur < (int)s.size()) {
            if (isalpha(s[cur])) {
                res += s[cur++];
            }
            else if (isdigit(s[cur])) {
                num = num*10 + (s[cur++]-'0');
            }
            else if (s[cur] == '[') {
                string t = parse(s, ++cur);
                while (num--) res += t;
                num = 0;
            }
            else if (s[cur] == ']') {
                ++cur;
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.decodeString("1[2[3[4[a]]]]") <<endl;
    return 0;
}

