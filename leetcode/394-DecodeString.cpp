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
    
    string parse(string& s, int& i) {
        string res;
        int num = 0;
        while (i < (int)s.size()) {
            if (isalpha(s[i])) res += s[i++];
            else if (isdigit(s[i])) num = num*10 + s[i++]-'0';
            else if (s[i] == '[') {
                string p = parse(s, ++i);
                while (num--) res += p;
                num = 0;
            }
            else if (s[i] == ']') {
                ++i;
                break;
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

