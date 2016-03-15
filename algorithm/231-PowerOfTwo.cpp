#include <iostream>
using namespace std;

// if n is power of 2, there must be only one 1 in its bits
// so use the n&(n-1) trick
bool isPowerOfTwo(int n) {
    return n > 0 && !(n&(n-1));
}

int main() {
    cout << isPowerOfTwo(7) << endl;
    return 0;
}
