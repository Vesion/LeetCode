#include <iostream>
using namespace std;

// Same with 'Beauty of Programming' Problem2.1

// Solution 1 : iterate and count, O(n)
int hammingWeight_On(uint32_t n) {
    int count = 0;;
    while (n) {
        count += n&1;
        n >>= 1;
    }
    return count;
}


// Solution 2 : O(k), k is number of 1 bits
int hammingWeight_Ok(uint32_t n) {
    int count = 0;
    while (n) {
        ++count;
        n &= (n-1);
    }
    return count;
}

int main() {
    cout << hammingWeight_On(11) << endl;
    cout << hammingWeight_Ok(11) << endl;
    return 0;
}
