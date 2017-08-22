#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Problem 1 : Given a 64-bit integer, is it the sum of i (i>=2) continuous integers? Print out all these equations.
// Problem 2 : Proof that if a 64-bit integer is the sum of i continuous integers or not.
// Problem 3 : Which 64-bit integer has the most number of integers in sum sequence equation?


using ll = long long;

// Problem 1:
// assume has i(>=2) integers, the first one is j(>=1), then
//      n = j + (j+1) + (j+2) + ... + (j+i-1) = i*(i-1)/2+i*j   (i >= 2)
// thus
//      (n-i*(i-1)/2) % i = 0
void printEquation(ll n) {
    if (n < 3) return;
    for (int i = 2; i*(i-1)<n; ++i) {
        if ((n-i*(i-1)/2) % i == 0) {
            int j = (n-i*(i-1)/2) / i;
            cout << "n = ";
            for (int k = 0; k < i; ++k)
                cout << j+k << " ";
            cout << endl;
        }
    }
}


// Problem 2-3 : http://blog.csdn.net/yutianzuijin/article/details/10300067/



int main() {
    printEquation(9); 
    return 0;
}
