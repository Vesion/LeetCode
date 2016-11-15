#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        while (i >= 0 && s[i] == ' ') --i;
        int j = i;
        while (j >= 0 && isalpha(s[j])) --j;
        return i-j;
    }
};

int main() {
    Solution s;
    return 0;
}

