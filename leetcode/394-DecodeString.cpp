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
        return decode(s, i);
    }

    // decode the token in []
    // assume there must be digits before [
    string decode(const string& s, int& i) {
        int t = 0;
        string res;
        for (; i < s.size(); ++i) {
            if (isalpha(s[i])) res += s[i];
            else if (isdigit(s[i])) t = t*10 + (s[i] - '0');
            else if (s[i] == '[') {
                const string sub = decode(s, ++i);
                while (t--) res += sub;
                t = 0;
            } else {  // s[i] == ']'
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

