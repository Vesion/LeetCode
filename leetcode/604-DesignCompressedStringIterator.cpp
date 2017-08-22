#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class StringIterator {
private:
    string s;
    int i, n, ch, cnt;
public:
    StringIterator(string compressedString) {
        s = compressedString;
        i = 0, n = s.size(), ch = 0, cnt = 0;
    }
    
    char next() {
        if (hasNext()) {
            cnt--;
            return ch;
        } else return ' ';
    }
    
    bool hasNext() {
        if (cnt == 0 && i == n) return false;
        if (cnt == 0) {
            ch = s[i++];
            while (i < n && isdigit(s[i])) cnt = cnt*10 + (s[i++]-'0');
        }
        return true;
    }
};


int main() {
    return 0;
}
