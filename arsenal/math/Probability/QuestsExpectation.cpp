#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// https://hihocoder.com/problemset/problem/1489
//
// Solution: The quests expectation for each item is independent, so the final result is the sum of each one's.

const int MAX = 1000005;

// p: initial probability for ith item
// q: the increasing probability after each quest
double getExpectation(int p, int q) {
    double quests = 1;
    double other = 1;
    while (p < 100) {
        other *= (100-p)/100.0; // we need one more quest, only if we don't get the item in this quest
        quests += other;
        p += q;
    }
    return quests;
}

int main() {
    int P, Q, N;
    cin >> P >> Q >> N; 
    double res = 0;
    for (int i = 0; i < N; ++i) {
        res += getExpectation(P, Q); // calculate ith item's expectation
        P /= 2;
    }
    printf("%.2f\n", res);
    return 0;
}

