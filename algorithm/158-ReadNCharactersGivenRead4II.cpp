#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string content = "abcdefghij";
int fi = 0;
int read4(char *buf) {
    int res = 0;
    for (int i = 0; i < 4; ++i) {
        if (fi < (int)content.size())
            buf[res++] = content[fi++];
        else break;
    }
    return res;
}

int read4(char *buf);

class Solution {
private:
    int ptr = 0;
    int cnt = 0;
    char tmp[4];

public:
    int read(char *buf, int n) {
        int res = 0;
        while (res < n) {
            if (ptr == 0) cnt = read4(tmp);
            if (cnt == 0) break; // eof
            while (res < n && ptr < cnt)
                buf[res++] = tmp[ptr++];
            if (ptr >= cnt) ptr = 0;
        }
        return res;
    }
};

int main() {
    Solution s;
    char t[5] = {0};
    cout << s.read(t, 1) << " " << t << endl;
    cout << s.read(t, 1) << " " << t << endl;
    cout << s.read(t, 1) << " " << t << endl;
    cout << s.read(t, 1) << " " << t << endl;
    cout << s.read(t, 1) << " " << t << endl;
    return 0;
}
