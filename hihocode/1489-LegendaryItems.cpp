#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1000005;

double getExpectation(int p, int q) {
    double quests = 1;
    double e = 1;
    while (p < 100) {
        e *= (100-p)/100.0;
        quests += e;
        p += q;
    }
    return quests;
}

int main() {
    int P, Q, N;
    cin >> P >> Q >> N; 
    double res = 0;
    for (int i = 0; i < N; ++i) {
        res += getExpectation(P, Q);
        P /= 2;
    }
    printf("%.2f\n", res);
    return 0;
}
