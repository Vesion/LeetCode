#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Given a random function rand5() which can generate 0~4 at same probability
// Use rand5() to implement a function rand7() which can generate 0~6 at same probability
//
// Idea:
//      How to generate larger integers?
//      We can use * and + to extend our generating range. Then use % to get final result.
//
//      But the key is how to guarantee the same probability?
//      k*randk() + randk():
//                randk() -> 0, 1, 2, ..., k-1
//              k*randk() -> 0, k, 2*k, ..., k*(k-1)
//      k*randk()+randk() -> [0, 1, ..., k-1], [k, k+1, ..., k+k-1], ..., [k*(k-1), ..., k*k-1]
//
//      So we can use 5*rand5()+rand5() to generate [0, 24] at same probability
//      we only care about [0, 20], because [21, 24] will increase probability of [0, 3]
//      so use while to ignore [21, 24]
//      [0, 20] % 7 = [0, 6]

int rand5() { return rand() % 5; }

int rand7() {
    int res = INT_MAX;
    while (res > 20) res = 5 * rand5() + rand5();
    return res % 7;
}


// Follow up:
//      Given the basic random function rand2() which generates 0,1 at same probability
//      How to implement any other random function randk() ?
//
// Idea:
//      Bitmap, 01-generator can generate 0 and 1, we can use them as bits
//      We can generate bits until we have enough to represent the number k-1 in binary


int main() {
    for (int i = 0; i < 100; ++i) cout << rand7() << " ";
    return 0;
}

