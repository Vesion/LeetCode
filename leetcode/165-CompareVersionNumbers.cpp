#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


// Implement string split
class Solution0 {
public:
    int compareVersion(string version1, string version2) {
        vector<string> s1 = split(version1), s2 = split(version2);
        int m = s1.size(), n = s2.size();
        int i = 0, j = 0;
        for (; i < m && j < n; ++i, ++j) {
            int x1 = stoi(s1[i]), x2 = stoi(s2[i]);
            if (x1 < x2) return -1;
            if (x1 > x2) return 1;
        }
        while (i < m) if (stoi(s1[i++]) != 0) return 1;
        while (j < n) if (stoi(s2[j++]) != 0) return -1;
        return 0;
    }

    vector<string> split(const string& s) {
        vector<string> res;
        int i = 0;
        while (true) {
            int j = s.find('.', i);
            if (j != string::npos) res.push_back(s.substr(i, j-i));
            else { res.push_back(s.substr(i)); break; }
            i = j+1;
        }
        return res;
    }
};

// Use std string stream
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream ss1(version1), ss2(version2);
        string v1, v2;
        while (true) {
            int n1 = getline(ss1, v1, '.') ? stoi(v1) : 0;
            int n2 = getline(ss2, v2, '.') ? stoi(v2) : 0;
            if (n1 != n2) return n1 > n2 ? 1 : -1;
            if (ss1.eof() && ss2.eof()) break;
        }
        return 0;
    }
};

int main() {
    Solution s;
    cout << s.compareVersion("1.1", "1") << endl;
    return 0;
}

