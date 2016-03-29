#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// do NOT fear to use interger rather than string!!

// Solution 1 : convert manually
int compareVersion(string version1, string version2) {
    int l1 = version1.size(), l2 = version2.size();
    int n1 = 0, n2 = 0;
    for (int i = 0, j = 0; i < l1 || j < l2; ++i, ++j) {
        while (i < l1 && version1[i] != '.') {
            n1 = n1 * 10 + (version1[i] - '0');
            ++i;
        }
        while (j < l2 && version2[j] != '.') {
            n2 = n2 * 10 + (version2[j] - '0');
            ++j;
        }
        if (n1 > n2) return 1;
        if (n2 > n1) return -1;
        n1 = n2 = 0;
    }
    return 0;
}


// Solution 2 : use stringstream
int compareVersion_stl(string version1, string version2) {
    istringstream in1(version1), in2(version2);
    string v1, v2;
    while (true) {
        int n1 = getline(in1, v1, '.') ? stoi(v1) : 0;
        int n2 = getline(in2, v2, '.') ? stoi(v2) : 0;
        if (n1 > n2) return 1;
        if (n1 < n2) return -1;
        if (v1.empty() && v2.empty()) return 0;
        v1 = v2 = "";
    }
}

int main() {
    cout << compareVersion("1.1.1", "1.01.1") << endl;;
    cout << compareVersion_stl("1.0.1", "1") << endl;
}
