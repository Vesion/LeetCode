#include <iostream>
#include <string>
using namespace std;

// do NOT fear to use interger rather than string!!
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

int main() {
    cout << compareVersion("1.1.1", "1.01.1");
}
