#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validate(int x) {
        return ((x ^ 0x80) > 0x3f);
    }

    bool validUtf8(vector<int>& data) {
        int i = 0;
        while (i < (int)data.size()) {
            if ((data[i] ^ 0xF0) <= 0x07) { // u4;
                int c = 3;
                while (c--) if (validate(data[++i])) return false;
            } else if ((data[i] ^ 0xE0) <= 0x0F) { // u3
                int c = 2;
                while (c--) if (validate(data[++i])) return false;
            } else if ((data[i] ^ 0xC0) <= 0x1F) { // u2
                int c = 1;
                while (c--) if (validate(data[++i])) return false;
            } else if ((data[i] ^ 0x0) <= 0x7F) { // u1
                ;
            } else return false;
            ++i;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> data = {235, 140, 4};
    cout << s.validUtf8(data) <<endl;
    return 0;
}
