#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Count the number of 1s in an integer


int countOnes(int n) {
    int r = 0;
    while (n) {
        ++r;
        n &= (n-1);
    }
    return r;
}


int main() {
    cout << countOnes(0xf7ff) << endl;
    return 0;
}
