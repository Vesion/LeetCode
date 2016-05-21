#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// Break n into number no greater than 4, because 5 can be broken into 2+3 whose product is 6 greater than 5
int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n == 4) return 4;
    int i = n / 3, j = n % 3;
    if (j == 1) --i, j = 4;
    else if (j == 0) j = 1;
    return pow(3.0, i) * j;
}

int main() {
    for (int i = 2; i < 15; ++i)
        cout << i << " " << integerBreak(i) << endl;
    return 0;
}
