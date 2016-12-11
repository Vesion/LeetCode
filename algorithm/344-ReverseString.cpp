#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.size()-1;
        while (i <= j) swap(s[i++], s[j--]);
        return s;
    }
};

int main() {
    Solution s;
    return 0;
}
