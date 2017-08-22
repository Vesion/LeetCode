#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream ss1(version1), ss2(version2);
        string v1, v2;
        while (true) {
            int n1 = getline(ss1, v1, '.') ? stoi(v1) : 0;
            int n2 = getline(ss2, v2, '.') ? stoi(v2) : 0;
            if (n1 != n2) return n1 > n2 ? 1 : -1;
            if (ss1.eof() && ss2.eof()) return 0;
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.1", "1") << endl;
    return 0;
}

