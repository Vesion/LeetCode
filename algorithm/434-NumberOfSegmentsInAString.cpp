#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

// Solution 1 : stringstream
class Solution_1 {
public:
    int countSegments(string s) {
        istringstream in(s);
        int res = 0;
        string seg;
        while (in >> seg) ++res;
        return res;
    }
};


// Solution 2
class Solution {
public:
    int countSegments(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] != ' ' && (i+1 == n || s[i+1] == ' ')) ++res;
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
