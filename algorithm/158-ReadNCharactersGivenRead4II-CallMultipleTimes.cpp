#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string content = "abcdefghijklmnopq";
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
    char cache[4];
    int p = 0; // cache's pointer
    int len = 0; // cache's real length (return by read4)

public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        while (res < n) {
            if (p == 0) len = read4(cache); // we need to call read4 to fill cache
            if (len == 0) break; // read4 return 0, it means file has been read over
            if (p < len) buf[res++] = cache[p++]; // if pointer hasn't reach end, fill buf using cache
            else p = 0; // else, it means cache has been read over, reset cache's pointer
        }
        return res;
    }
};

int main() {
    Solution s;
    char t[100];
    cout << s.read(t, 1) << " " << t << endl;
    cout << s.read(t, 2) << " " << t << endl;
    cout << s.read(t, 3) << " " << t << endl;
    cout << s.read(t, 4) << " " << t << endl;
    cout << s.read(t, 5) << " " << t << endl;
    cout << s.read(t, 6) << " " << t << endl;
    return 0;
}
