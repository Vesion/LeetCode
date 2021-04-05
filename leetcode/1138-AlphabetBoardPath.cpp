#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int start = 0;
        for (int i = 0; i < target.size(); ++i) {
            res += get(start, target[i]-'a');
            start = target[i]-'a';
        }
        return res;
    }

    string get(int x, int y) {
        int ix = x/5, iy = x%5;
        int jx = y/5, jy = y%5;
        string res;
        if (jy < iy) res += string(iy-jy, 'L');
        if (jx > ix) res += string(jx-ix, 'D');
        if (jx < ix) res += string(ix-jx, 'U');
        if (jy > iy) res += string(jy-iy, 'R');
        res += "!";
        return res;
    }
};

int main() {
    return 0;
}
