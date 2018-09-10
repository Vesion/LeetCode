#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// implement some of <cstring> apis


size_t strlen(const char* s) {
    const char* c;
    for (c = s; *c; ++c);
    return c-s;
}


char* strcpy(char* to, const char* from) {
    for (char* t = to; *from; *t++ = *from++);
    return to;
}


int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 > *s2) return 1;
        if (*s2 > *s1) return -1;
        ++s1, ++s2;
    }
    if (*s1) return 1;
    if (*s2) return -1;
    return 0;
}


int stoi(string str) {
    int n = str.size();
    if (n == 0) return 0;

    int i = 0;
    int sign = 1;
    while (str[i] == ' ') ++i;
    if (str[i] == '+') { sign = 1; ++i; }
    else if (str[i] == '-') { sign = -1; ++i; }

    int result = 0;
    for (; i < n; ++i) {
        if (str[i] < '0' || str[i] > '9') break;
        if (result > INT_MAX/10 || (result == INT_MAX/10 && str[i]-'0' > INT_MAX%10))
            return sign == 1 ? INT_MAX : INT_MIN;
        result = result * 10 + str[i] - '0';
    }
    return result * sign;
}


// brute force, O(m*n)
char* strstr(const char* s, const char* t) {
    if (!s || !t) return (char*)s;
    for (const char* p = s; *p; ++p) {
        if (*p == *t) {
            const char *t1 = t, *p1 = p;
            while (*t1 && *p1 && *t1 == *p1) ++t1, ++p1;
            if (!*t1) return (char*)p;
        }
    }
    return NULL;
}



int main() {
    const char* s = "abcd";    
    cout << strlen(s)<<endl;;

    char t[20];
    strcpy(t, s);
    cout << t << endl;

    t[0] = 'b';
    cout << strcmp(t, s) <<endl;;

    char* r = strstr("123456", "234");
    cout << r<<endl;
    return 0;
}
