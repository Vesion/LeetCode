#include <iostream>
#include <string>
using namespace std;

/*
 * Very classical string match problem
 * Solution-1 : Brute-Force O(m * n)
 * Solution-2 : KMP O(n + m)
 * Solution-3 : Boyer-Mooer O(n / m)
 */

// Solution-1
int strStr(string haystack, string needle) {
    int hlen = haystack.size();
    int nlen = needle.size();
    if (nlen == 0)
        return 0;
    if (hlen < nlen)
        return -1;
    int i = 0, j;
    for (; i <= hlen - nlen; ++i) {
        for (j = 0; j < nlen; ++j) {
            if (haystack[i+j] != needle[j])
                break;
        }
        if (j == nlen)
            return i;
    }
    return -1;
}

int main() {
    cout << strStr("mississippi" ,"issip");
    return 0;
}
