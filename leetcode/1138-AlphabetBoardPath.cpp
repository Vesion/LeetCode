#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int m[26][2];
    int x = 0, y = 0;

    string alphabetBoardPath(string target) {
        for (int i = 0; i < 26; ++i) {
            m[i][0] = i/5;
            m[i][1] = i%5;
        }
        string res;
        for (char c : target) res += move(c);
        return res;
    }

    string move(char c) {
        const int nx = m[c-'a'][0], ny = m[c-'a'][1];
        string res;
        // Note the order for case e.g. "zdz"
        res += string(max(0, x-nx), 'U');
        res += string(max(0, y-ny), 'L');
        res += string(max(0, ny-y), 'R');
        res += string(max(0, nx-x), 'D');
        x = nx, y = ny;
        return res + "!";
    }
};

int main() {
    return 0;
}
