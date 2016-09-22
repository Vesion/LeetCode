#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : top-down parser, recursive descent
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

    string decodeString(string& s, int& i) {
        string r = "";

        while (i < (int)s.size()) {
            if (isdigit(s[i])) {
                int c = 0;
                while (isdigit(s[i])) c = c * 10 + (s[i++] - '0');
                ++i; // eat '['
                string t = decodeString(s, i);
                while (c--) r += t;
                ++i; // eat ']'
            }
            else if (isalpha(s[i])) r += s[i++];
            else break; // ']'
        }

        return r;
    }
};

int main() {
    Solution s;
    cout << s.decodeString("2[abc]3[cd]ef") <<endl;
    return 0;
}
