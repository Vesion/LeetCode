#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int c = 0;
        for (int d : data) {
            if (c == 0) {
                if ((d >> 3) == 0b11110) c = 3;
                else if ((d >> 4) == 0b1110) c = 2;
                else if ((d >> 5) == 0b110) c = 1;
                else if ((d >> 7) != 0) return false;
            } else {
                if ((d >> 6) != 0b10) return false;
                --c;
            }
        }
        return c == 0;
    }
};

int main() {
    Solution s;
    vector<int> data = {197, 130, 1};
    cout << s.validUtf8(data) << endl;
    return 0;
}

