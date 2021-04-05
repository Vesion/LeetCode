#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string modifyString(string s) {
        string r = s;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                if (i == 0) {
                    if (i+1 < n && s[i+1] != '?') r[i] = nextc(s[i+1]);
                    else r[i] = 'a';
                } else {
                    if (nextc(r[i-1]) == s[i+1]) r[i] = prevc(r[i-1]);
                    else r[i] = nextc(r[i-1]);
                }
            }
        }
        return r;
    }

    char nextc(char a) {
        return 'a' + (a-'a'+1)%26;
    }

    char prevc(char a) {
        return 'a' + (a-'a'-1+26)%26;
    }
};

int main() {

}