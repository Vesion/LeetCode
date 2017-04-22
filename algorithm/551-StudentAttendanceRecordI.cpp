#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for (char& c : s) {
            if (c == 'L') ++l;
            else {
                l = 0;
                if (c == 'A') ++a;
            }
            if (a > 1 || l > 2) return false;
        }
        return true;
    }
};


int main() {
    return 0;
}
