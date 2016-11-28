#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Forward declaration of the read4 API.
// Read from file into buf.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        bool eof = false;
        while (!eof && res < n) {
            int c = read4(buf);
            if (c < 4) eof = true;
            c = min(c, n-res);
            res += c;
            buf += c;
        }
        return res;
    }
};

int main() {
    
    return 0;
}
