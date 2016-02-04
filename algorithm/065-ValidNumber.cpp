#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// use 'strtod' in stdlib.h
bool isNumber(string s) {
    const char *start = s.c_str();
    char *end;
    strtod(start, &end);
    if (end == start)
        return false;
    for (; *end; ++end) {
        if (*end != ' ')
            return false;
    }
    return true;
}


// or brute-froce, refer to LeiTang


// or automata, refer to http://blog.csdn.net/kenden23/article/details/18696083

int main() {
    cout << isNumber(string("  .1e10")) << endl;
    return 0;
}
