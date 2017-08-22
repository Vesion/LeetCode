#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(const char *source, const char *target) {
        if (!source || !target) return -1;
        int sl = strlen(source), tl = strlen(target);
        if (sl < tl) return -1;
        for (int i = 0; i <= sl-tl; ++i) {
            bool equal = true;
            for (int j = 0; j < tl; ++j) if (source[i+j] != target[j]) equal = false;
            if (equal) return i;
        }
        return -1;
    } 
};

int main() {
    Solution s;
    cout << s.strStr("", nullptr) << endl;
    return 0;
}
