#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool isMatchp(const char* s, const char* p) {
    if (*p == '\0')
        return *s == '\0';

    if (*(p+1) != '*' || *(p+1) == '\0') {
        if (*s == '\0' || (*p != '.' && *p != *s))
            return false;
        return isMatchp(s+1, p+1);
    }

    int len = strlen(s);
    int i = -1;
    while (i < len && (i < 0 || *p == '.' || *p == *(s+i))) {
        if (isMatchp(s+i+1, p+2))
            return true;
        i++;
    }
    return false;
}

bool isMatch(string s, string p) {
    return isMatchp(s.c_str(), p.c_str());
}

int main() {
    cout<<isMatch("aabc", "d*a*b*.*");
    return 0;
}
